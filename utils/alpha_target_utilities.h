/**
 * @file alpha_target_utilities.h
 *
 * Utility library for the implementation of the alpha
 * compiler.
 *
 * Created for the purposes of the syntax analyzer, as part
 * of the project for HY-340, Spring 2024
 *
 * Computer science department of Crete, Greece
 *
 * -Team members: 
 * @Dimitris Segkesser
 * @Nikoleta Xenaki
 * @Vicky Miliaraki
 *
 * @date 22/5/2024
*/

#ifndef ALPHA_TARGET_UTILITIES
#define ALPHA_TARGET_UTILITIES

#include "alpha_bison_utilities.h"
#include "alpha_general_types.h"
#include "alpha_stack.h"

#define CURR_SIZE_INSTR (totalInstructions * sizeof(instruction))
#define NEW_SIZE_INSTR (EXPAND_SIZE * sizeof(instruction) + CURR_SIZE_INSTR)

#define CURR_SIZE_NUM (totalNumConsts * sizeof(double))
#define NEW_SIZE_NUM (EXPAND_SIZE * sizeof(double) + CURR_SIZE_NUM)

#define CURR_SIZE_STRING (totalStringConsts * sizeof(char*))
#define NEW_SIZE_STRING (EXPAND_SIZE * sizeof(char*) + CURR_SIZE_STRING)

#define CURR_SIZE_LIBFUNC (totalNamedLibfuncs * sizeof(char*))
#define NEW_SIZE_LIBFUNC (EXPAND_SIZE * sizeof(char*) + CURR_SIZE_LIBFUNC)

#define CURR_SIZE_USERFUNC (totalUserFuncs * sizeof(userFunc))
#define NEW_SIZE_USERFUNC (EXPAND_SIZE * sizeof(userFunc) + CURR_SIZE_USERFUNC)

typedef struct incomplete_jump   incomplete_jump;
typedef void(*generator_func_t)(quad*);

struct incomplete_jump{
    unsigned            instrNo;
    unsigned            iaddress;
    incomplete_jump*    next;
};

incomplete_jump*    ij_head = NULL;
unsigned            ij_total = 0;

//Declarations
unsigned        consts_newstring(char* s);
unsigned        consts_newnumber(double n);
unsigned        libfuncs_newused(char* s);
unsigned        userfuncs_newfunc(SymbolTableEntry_t* sym, bool noFuncConst, unsigned scope);
void            add_incomplete_jump(unsigned instrNo, unsigned iaddress);
void            emit_instruction(instruction instr);
unsigned int    nextInstructionLabel();
unsigned        userFuncs_add(char* id, unsigned taddress, unsigned totalArgs, unsigned totalLocals, bool noFuncConst, unsigned scope);
void            expand_constnumbers();
void            expand_conststrings();
void            expand_constuserfuncs();
void            expand_constlibfuncs();
void            generate_relational(vmopcode op, quad *quadInput);
//
void generate(vmopcode op, quad *q);
void generate_ADD(quad *q);
void generate_SUB(quad *q);
void generate_MUL(quad *q);
void generate_DIV(quad *q);
void generate_MOD(quad *q);
void generate_UMINUS(quad* q);
void generate_NEWTABLE(quad *q);
void generate_TABLEGETELM(quad *q);
void generate_TABLESETELEM(quad *q);
void generate_ASSIGN(quad *q);
void generate_NOP(quad *q);

void generate_JUMP(quad *q);
void generate_IF_EQ(quad *q);
void generate_IF_NOTEQ(quad *q);
void generate_IF_GREATER(quad *q);
void generate_IF_GREATEREQ(quad *q);
void generate_IF_LESS(quad *q);
void generate_IF_LESSEQ(quad *q);
void generate_CALL(quad* q);
void generate_RETURN(quad* q);
void generate_RETVAL(quad* q);
void generate_PARAM(quad* q);
void generate_FUNCSTART(quad* q);
void generate_FUNCEND(quad* q);
void generateTcode(unsigned int totalQuads);

//
double*          numConsts;
unsigned         currNumConst = 0;
unsigned         totalNumConsts = 0;
char**           stringConsts;
unsigned         currStringConst = 0;
unsigned         totalStringConsts = 0;
char**           namedLibfuncs;
unsigned         currNamedLibFuncConst = 0;
unsigned         totalNamedLibfuncs = 0;
userFunc*        userFuncs;
unsigned         currUserFuncConst = 0;
unsigned         totalUserFuncs = 0;
unsigned         totalInstructions = 1;
unsigned         currentInstruction = 1;
instruction*     instructions;
incomplete_jump* incomplete_jumps = NULL;
unsigned         current_tscope;
//

generator_func_t generators[] = {
    generate_ASSIGN,
    generate_ADD,
    generate_SUB,
    generate_MUL,
    generate_DIV,
    generate_MOD,
    generate_UMINUS,
    generate_JUMP,
    generate_IF_EQ,
    generate_IF_NOTEQ,
    generate_IF_LESSEQ,
    generate_IF_GREATEREQ,
    generate_IF_LESS,
    generate_IF_GREATER,  
    generate_CALL,
    generate_PARAM,
    generate_FUNCSTART,
    generate_FUNCEND,
    generate_NEWTABLE,
    generate_TABLEGETELM,
    generate_TABLESETELEM,
    generate_RETVAL, 
    generate_RETURN,
    generate_NOP
};

/**
 * For testing only
*/
char* vmarg_str[] = {
    "label",
    "global",
    "formal",
    "local",
    "number",
    "string",
    "bool",
    "nil",
    "userfunc",
    "libfunc",
    "retval",
    "invalid"
};

void printInstr(FILE* file) {
    fprintf(file, "\033[0;33m======Num consts======\033[0m\n");
    for(unsigned index=0;index<currNumConst;index++){
        fprintf(file, "\033[0;34mNums[%d]: %f", index, numConsts[index]);
        fprintf(file, "\033[0m\n");
    }
    fprintf(file, "\033[0;33m======String consts======\033[0m\n");
    for(unsigned index=0;index<currStringConst;index++){
        fprintf(file, "\033[0;34mStrings[%d]: %s", index, stringConsts[index]);
        fprintf(file, "\033[0m\n");
    }
    fprintf(file, "\033[0;33m======Fuction consts======\033[0m\n");
    for(unsigned index=0;index<currUserFuncConst;index++){
        fprintf(file, "\033[0;34mUser functions[%d]: %s", index, userFuncs[index].id);
        fprintf(file, "\033[0m\n");
    }
    fprintf(file, "\033[0;33m======Library consts======\033[0m\n");
    for(unsigned index=0;index<currNamedLibFuncConst;index++){
        fprintf(file, "\033[0;34mLibrary functions[%d]: %s", index, namedLibfuncs[index]);
        fprintf(file, "\033[0m\n");
    }
    fprintf(file, "\n");
    for(unsigned index=1;index<currentInstruction;index++){
        instruction *instr = instructions + index;

        fprintf(file, "\033[0;33mSource line: %3d, line: %3d: %10s", instr->srcLine, instr->targetLine, targetToString[instr->opcode]);
        fprintf(file,  " %5d(%s)\t%5d (%s)\t%5d(%s)", instr->arg1.val, vmarg_str[instr->arg1.type] , 
            instr->arg2.val, vmarg_str[instr->arg2.type], instr->result.val, vmarg_str[instr->result.type]);
        fprintf(file, "\033[0m\n");
    }
}

unsigned consts_newstring(char *str){
    int i = 0;
    for(;i<currStringConst;i++){
        if(streq(stringConsts[i], str)){
            return i;
        }
    }

    if(currStringConst==totalStringConsts)
        expand_conststrings();

    char** s = stringConsts+currStringConst++;
    *s = str;

    return currStringConst-1;
}

unsigned consts_newnumber(double number){
    int i = 0;
    for(;i<currNumConst;i++){
        if(numConsts[i]==number){
            return i;
        }
    }

    if(currNumConst==totalNumConsts)
        expand_constnumbers();

    double* num = numConsts+currNumConst++;
    *num = number;

    return currNumConst-1;
}

unsigned libfuncs_newused(char *name){
    int i = 0;
    for(;i<currNamedLibFuncConst;i++){
        if(streq(namedLibfuncs[i], name)){
            return i;
        }
    }

    if(currNamedLibFuncConst==totalNamedLibfuncs)
        expand_constlibfuncs();

    char** s = namedLibfuncs+currNamedLibFuncConst++;
    *s = name;

    return currNamedLibFuncConst-1;
}

unsigned userfuncs_newfunc(SymbolTableEntry_t* sym, bool noFuncConst, unsigned scope){
    Function_t* f = sym->value.funcVal;

    // if(f==NULL)return -1;

    f->taddress = nextInstructionLabel();
    unsigned res = userFuncs_add(f->name, f->taddress, f->totalArgs, f->totalLocals, noFuncConst, scope);

    if(!noFuncConst)
        Funcstack_push(funcstack, f);

    return res;
}

unsigned userFuncs_add(char* id, unsigned taddress, unsigned totalArgs, unsigned totalLocals, bool noFuncConst, unsigned scope){
    int i = 0;
    for(int lookup_scope = scope;lookup_scope>=0;lookup_scope--){
        i = 0;
        for(;i<currUserFuncConst;i++){
            if(userFuncs[i].scope==lookup_scope&&streq(userFuncs[i].id, id)){
                return i;
            }
        }
    }

    if(noFuncConst)return -1;

    if(currUserFuncConst==totalUserFuncs)
        expand_constuserfuncs();

    userFunc* f = userFuncs+currUserFuncConst++;
    f->id = id;
    f->address = taddress;
    f->totalArgs = totalArgs;
    f->localSize = totalLocals;
    f->scope = scope;
    
    return currUserFuncConst-1;
}

void make_operand(expr* e, vmarg* arg, bool noFuncConst) {
    //ASSERT(e);
    if (e==NULL) {
        arg->type=invalid_a;
        return;
    }

    switch(e->type) {
        case var_e:
        case tableitem_e:
        case arithexpr_e:
        case boolexpr_e:
        case assignexpr_e:
        case newtable_e:
            ASSERT(e->sym);
            if(isTypeVariable(e->sym->type)){
                arg->val = e->sym->value.varVal->offset;
            }else{
                arg->val = e->sym->value.funcVal->offset;
            }
            // printf("SPACEEEEEEEE before%d\n", e->sym->space);
            if (Funcstack_isempty(pfunc_jumpstack) && e->sym->space!=FORMALARG) {
                // printf("funcstack is %d\n", pfunc_jumpstack->size);
                e->sym->space=PROGRAMVAR;
            } 
            //printf("SPACEEEEEEEE %d\n", e->sym->space);
            switch(e->sym->space){
                case PROGRAMVAR:    arg->type = global_a; break;
                case FUNCTIONLOCAL: arg->type = local_a;  break;
                case FORMALARG: arg->type = formal_a; break;
                default: ASSERT(0);
            }
            break;
        case constbool_e:
            arg->val = e->boolConst;
            arg->type = bool_a;
            break;
        case conststring_e:
            arg->val = consts_newstring(e->strConst);
            arg->type = string_a;
            break;
        case constnum_e:
            arg->val = consts_newnumber(e->numConst);
            arg->type = number_a;
            break;
        case nil_e:
            arg->type = nil_a;
            break;
        case callfunc_e:
        case programfunc_e:
            ASSERT(e->sym);

            arg->type = userfunc_a;
            unsigned scope;
            if(isTypeVariable(e->sym->type)){
                scope = e->sym->value.varVal->scope;
                arg->val = userfuncs_newfunc(e->sym, true, scope);
            }else{
                scope = e->sym->value.funcVal->scope;
                e->sym->value.funcVal->totalLocals=e->totalLocals;
                arg->val = userfuncs_newfunc(e->sym, noFuncConst, scope);

            }
            break;
        case libraryfunc_e:
            arg->type = libfunc_a;
            ASSERT(e->sym);
            if(isTypeVariable(e->sym->type)){
                arg->val = libfuncs_newused(e->sym->value.varVal->name);
            }else{
                arg->val = libfuncs_newused(e->sym->value.funcVal->name);
            }
            break;
        default:
            ASSERT(0);
    }
}

void make_numberoperand(vmarg* arg, double val){
    arg->val = consts_newnumber(val);
    arg->type = number_a;
}

void make_booloperand(vmarg* arg, bool val){
    arg->val = val;
    arg->type = bool_a;
}

void make_retvaloperand(vmarg* arg){
    arg->type = retval_a;
}

void patchInstrLabel(unsigned int instrNum, unsigned int taddress){
    instructions[instrNum].result.val = taddress;
}

void add_incomplete_jump(unsigned instrNo, unsigned iaddress) {
    incomplete_jump* new_jump = (incomplete_jump*)safe_malloc(sizeof(incomplete_jump));
    new_jump->instrNo = instrNo;
    new_jump->iaddress = iaddress;
    new_jump->next = incomplete_jumps;
    incomplete_jumps = new_jump;
};

void patchIncompleteJumps(unsigned int totalQuads){
    for(incomplete_jump* ij = incomplete_jumps; ij ; ij = ij->next){
        if(ij->iaddress == totalQuads){
            patchInstrLabel(ij->instrNo, currentInstruction);
        }else{
            patchInstrLabel(ij->instrNo, quads[ij->iaddress].taddress);
        }
    }
}

unsigned int nextInstructionLabel() { return currentInstruction; }

void nullify_instr(instruction* i){
    i->arg1.type = invalid_a;
    i->arg2.type = invalid_a;
    i->arg1.val = 0;
    i->arg2.val = 0;
    i->result.type = invalid_a;
    i->result.val = 0;
}

//Generators
void generate(vmopcode op, quad *q)
{
    
	instruction t;
	nullify_instr(&t);
	t.opcode = op;
	t.targetLine = nextInstructionLabel();
    t.srcLine = q->src_line;
    //if(op==tablegetelem_v&&q->arg1->sym!=NULL)printf("arg1 for get have a sym of %s \n", q->arg1->sym->value.varVal->name);
	make_operand(q->arg1, &t.arg1, false);
	make_operand(q->arg2, &t.arg2, false);
	make_operand(q->result, &t.result, false);

    q->taddress = nextInstructionLabel();

	emit_instruction(t);
}

void append_retlist(Function_t* f, unsigned int instrLabel)
{

	retlist *new_ret = f->retlist;

	if (new_ret == NULL)
	{

		new_ret = (retlist *)safe_malloc(sizeof(retlist));
		new_ret->instrLabel = instrLabel;
		new_ret->next = NULL;
		f->retlist = new_ret;
	}
	else
	{

		retlist *tmp = (retlist *)malloc(sizeof(retlist));
		tmp->instrLabel = instrLabel;
		tmp->next = NULL;

		retlist *ret_list = new_ret;
		while (ret_list!=NULL && ret_list->next != NULL)
		{
			ret_list = ret_list->next;
		}

		ret_list->next = tmp;
    }
}

void generateTcode(unsigned int totalQuads)
{

 
	int i;
	for (i=1; i < totalQuads; ++i)
	{

		curr_quad = i;

		(*generators[quads[i].op])(quads + i);
	}


	patchIncompleteJumps(totalQuads);

}

void generate_ADD(quad *q) { generate(add_v, q); }
void generate_SUB(quad *q) { generate(sub_v, q); }
void generate_MUL(quad *q) { generate(mul_v, q); }
void generate_DIV(quad *q) { generate(div_v, q); }
void generate_MOD(quad *q) { generate(mod_v, q); }
void generate_NEWTABLE(quad *q) { generate(newtable_v, q); }
void generate_TABLEGETELM(quad *q) { generate(tablegetelem_v, q); }
void generate_TABLESETELEM(quad *q) { generate(tablesetelem_v, q); }
void generate_ASSIGN(quad *q) {generate(assign_v, q); }

void generate_JUMP(quad *q){generate_relational(jump_v, q);}
void generate_IF_EQ(quad *q){generate_relational(jeq_v, q);}
void generate_IF_NOTEQ(quad *q){generate_relational(jne_v, q);}
void generate_IF_GREATER(quad *q){generate_relational(jgt_v, q);}
void generate_IF_GREATEREQ(quad *q){generate_relational(jge_v, q);}
void generate_IF_LESS(quad *q){generate_relational(jlt_v, q);}
void generate_IF_LESSEQ(quad *q){generate_relational(jle_v, q);}

void generate_CALL(quad* q){
    q->taddress = nextInstructionLabel();
    instruction t;
    t.opcode = call_v;
    t.targetLine = nextInstructionLabel();
    nullify_instr(&t);
    make_operand(q->arg1, &t.arg1, false);
    t.srcLine = q->src_line;
    emit_instruction(t);

}

void generate_RETURN(quad* q) {
    q->taddress = nextInstructionLabel();

    instruction t;
    t.opcode = assign_v;
    t.srcLine = q->src_line;
    nullify_instr(&t);

    //Skip assignment to retval if no return value exists
    if(q->arg1!=NULL){
        t.targetLine = nextInstructionLabel();
        make_retvaloperand(&t.result);
        make_operand(q->arg1, &t.arg1, false);
        emit_instruction(t);
    }

    Function_t* f = Funcstack_peek(funcstack);
    append_retlist(f, nextInstructionLabel());
    //printf("RET LABEL:%d \n",f->retlist->instrLabel);
    t.opcode=jump_v;
    t.targetLine = nextInstructionLabel();
    nullify_instr(&t);

    t.result.type=label_a;
    emit_instruction(t);

}

void generate_RETVAL(quad* q){
    q->taddress = nextInstructionLabel();
    instruction t;
    t.opcode = assign_v;
    t.targetLine = nextInstructionLabel(); t.srcLine = q->src_line;
    nullify_instr(&t);
    make_operand(q->result, &t.result, false);
    make_retvaloperand(&t.arg1);
    emit_instruction(t);
}

void generate_PARAM(quad* q){
    q->taddress = nextInstructionLabel();
    instruction t;
    t.opcode = pusharg_v;
    t.targetLine = nextInstructionLabel(); t.srcLine = q->src_line;
    nullify_instr(&t);
    make_operand(q->arg1, &t.arg1, false);
    //t.arg1.type = formal_a;
    emit_instruction(t);

}

void generate_FUNCSTART(quad* q){
    q->arg1->sym->value.funcVal->taddress = nextInstructionLabel();
    q->taddress = nextInstructionLabel();
    //userfuncs_newfunc(q->arg1->sym);
    Stack_push(pfunc_jumpstack, q->taddress);

    instruction t;
    t.opcode = jump_v;
    t.srcLine = q->src_line;
    t.targetLine = nextInstructionLabel();
    nullify_instr(&t);
    emit_instruction(t);
    t.opcode = funcenter_v;
    t.targetLine = nextInstructionLabel(); t.srcLine = q->src_line;
    nullify_instr(&t);
    make_operand(q->arg1, &t.result, false);
    make_retvaloperand(&t.arg1);
    emit_instruction(t);

}

void generate_FUNCEND(quad* q) {
    Function_t* f = Funcstack_pop(funcstack);
    while(f->retlist!=NULL){
        patchInstrLabel(f->retlist->instrLabel, nextInstructionLabel());
        f->retlist = f->retlist->next;
    }
    q->taddress = nextInstructionLabel();
    instruction t;
    t.opcode = funcexit_v;
    t.targetLine = nextInstructionLabel(); t.srcLine = q->src_line;
    nullify_instr(&t);
    make_operand(q->arg1, &t.result, true);
    emit_instruction(t);

    int jump_addr = Stack_pop(pfunc_jumpstack);
    instructions[jump_addr].result.type = label_a;
    instructions[jump_addr].result.val = nextInstructionLabel();
}

void generate_UMINUS(quad* q) {
    q->op = mul_i;
    q->arg2 = new_constnum(-1);
    generate_MUL(q);
}

void generate_NOP(quad *q)
{

	instruction t;
	//setArgsNull(&t);
	t.opcode = nop_v;
	t.targetLine = nextInstructionLabel(); t.srcLine = q->src_line;
	q->taddress = nextInstructionLabel();

	emit_instruction(t);
}

void generate_relational(vmopcode op, quad *quadInput)
{

	instruction t;
	//setArgsNull(&t);
	t.opcode = op;
	t.targetLine = nextInstructionLabel(); 
    t.srcLine = quadInput->src_line;
    nullify_instr(&t);

	make_operand(quadInput->arg1, &t.arg1, false);
	make_operand(quadInput->arg2, &t.arg2, false);

	t.result.type = label_a;

	if ((int)quadInput->label < nextQuadLabel())
		t.result.val = quads[(int)quadInput->label].taddress;
	else
		add_incomplete_jump(nextInstructionLabel(), quadInput->label);

	quadInput->taddress = nextInstructionLabel();
	emit_instruction(t);
}
//

void expand_instructions(){
    ASSERT(currentInstruction==totalInstructions);

    instructions = (instruction*)realloc(instructions, NEW_SIZE_INSTR);

    if(instructions==NULL){
        fprintf(stderr, "Error, unable to allocate memory\n");
        exit(EXIT_FAILURE);
    }

    totalInstructions += EXPAND_SIZE;
}

void emit_instruction(instruction instr){
    if(currentInstruction==totalInstructions)
        expand_instructions();

    *(instructions+currentInstruction++) = instr;
}

void expand_constnumbers(){
    assert(currNumConst==totalNumConsts);

    numConsts = (double*)realloc(numConsts, NEW_SIZE_NUM);
    totalNumConsts+=EXPAND_SIZE;
}

void expand_conststrings(){
    assert(currStringConst==totalStringConsts);

    stringConsts = (char**)realloc(stringConsts, NEW_SIZE_STRING);
    totalStringConsts+=EXPAND_SIZE;
}

void expand_constlibfuncs(){
    assert(currNamedLibFuncConst==totalNamedLibfuncs);

    namedLibfuncs = (char**)realloc(namedLibfuncs, NEW_SIZE_LIBFUNC);
    totalNamedLibfuncs+=EXPAND_SIZE;
}

void expand_constuserfuncs(){
    assert(currUserFuncConst==totalUserFuncs);

    userFuncs = (userFunc*)realloc(userFuncs, NEW_SIZE_USERFUNC);
    totalUserFuncs+=EXPAND_SIZE;
}

/**
 * This function generates the binary output file for the target code.
 * It follows the format:
 * <Number table length>
 * <Number table entries>
 * <String table length>
 * <String table entries>
 * <User function table length>
 * <User function table entries in the format <address> <local size> <id>>
 * <Library function table length>
 * <Library function table entries>
 * <(optional) some magic number to denote start of bytecode>
 *  * <number of program globals>
 * <number of instructions>
 * <bytecode of the target program>
*/
void generateBinaryFile(FILE* file){
    /*Number table*/
    fwrite(&currNumConst, sizeof(currNumConst), 1, file);
    //fprintf(file, "%d\n", currNumConst);
    for(unsigned i=0;i<currNumConst;i++){
        fwrite(&numConsts[i], sizeof(double), 1, file);
        //fprintf(file, "%f ", numConsts[i]);
    }
    /*String table*/
    fwrite(&currStringConst, sizeof(currStringConst), 1, file);
    //fprintf(file, "\n%d\n", currStringConst);
    for(unsigned i=0;i<currStringConst;i++){
        int len = strlen(stringConsts[i]);
        fwrite(&len, sizeof(len), 1, file);
        fwrite(stringConsts[i], sizeof(char), len, file);
        //fprintf(file, "%s ", stringConsts[i]);
    }
    /*User function table*/
    fwrite(&currUserFuncConst, sizeof(currUserFuncConst), 1, file);
    //fprintf(file, "\n%d\n", currUserFuncConst);
    for(unsigned i=0;i<currUserFuncConst;i++){
        fwrite(&userFuncs[i].address, sizeof(userFuncs[i].address), 1, file);
        userFuncs[i].localSize++;
        fwrite(&userFuncs[i].localSize, sizeof(userFuncs[i].localSize), 1, file);
        int len = strlen(userFuncs[i].id);
        fwrite(&len, sizeof(len), 1, file);
        fwrite(userFuncs[i].id, sizeof(char), len, file);
        //fprintf(file, "%s ", userFuncs[i].id);
    }
    /*Library function table*/
    fwrite(&currNamedLibFuncConst, sizeof(currNamedLibFuncConst), 1, file);
    //fprintf(file, "\n%d\n", currNamedLibFuncConst);
    for(unsigned i=0;i<currNamedLibFuncConst;i++){
        int len = strlen(namedLibfuncs[i]);
        fwrite(&len, sizeof(len), 1, file);
        fwrite(namedLibfuncs[i], sizeof(char), len, file);
        //fprintf(file, "%s ", namedLibfuncs[i]);
    }

    //fprintf(file, "\n\n");
    fwrite(&global_offset, sizeof(global_offset), 1, file);
    fwrite(&currentInstruction, sizeof(currentInstruction), 1, file);
    for(unsigned i=1;i<currentInstruction;i++){
        instruction t = instructions[i];        
        int buffer[] = {t.srcLine, t.opcode, t.arg1.type, t.arg1.val, t.arg2.type, t.arg2.val, t.result.type, t.result.val};
        fwrite(buffer, sizeof(buffer), 1, file);
        //fprintf(file, "%2d\t%2d:%2d\t%2d:%2d\t%2d:%2d\t\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6]);
    }
}

#endif
