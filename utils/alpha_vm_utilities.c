
/**
 * @file alpha_vm_utilities.c
 *
 * Utility library for the implementation of the alpha
 * syntax analyzer.
 *
 * Created for the purposes of the virtual machine, as part
 * of the project for HY-340, Spring 2024
 *
 * Computer science department of Crete, Greece
 *
 * -Team members: 
 * @Dimitris Segkesser
 * @Nikoleta Xenaki
 * @Vicky Miliaraki
 *
 * @date 31/5/2024
*/

#include "alpha_vm_utilities.h"
#include "alpha_general_utilities.h"


avm_memcell ax, bx, cx;
avm_memcell retval;
unsigned top, topsp;

avm_memcell     stack[AVM_STACKSIZE];

avm_table*      avm_tablenew();
void            avm_tabledestroy(avm_table* t);
avm_memcell*    avm_tablegetelem(avm_table *table, avm_memcell *index);
void            avm_tablesetelem(avm_table *table, avm_memcell *index, avm_memcell *content);
void            avm_tablebucketdestroy(avm_table_bucket** p);
void            avm_tableincrefcounter(avm_table* t);
void            avm_memcellclear (avm_memcell* m);
double          consts_getnumber(unsigned int val);
char*           consts_getstring(unsigned int val);
char*           libfuncs_getused(unsigned int val);
userFunc*       avm_getfuncinfo(unsigned int val);
avm_memcell*    avm_translate_operand(vmarg* arg, avm_memcell* reg);
extern void     memclear_string(avm_memcell* m);
extern void     memclear_table(avm_memcell* m);
void            avm_assign(avm_memcell* lv, avm_memcell* rv);
void            avm_callsaveenviroment();
void            avm_push_ennvalue(unsigned val);
void            avm_dec_top();
double          add_impl(double x, double y) {return x+y;};
double          sub_impl(double x, double y) {return x-y;};
double          mul_impl(double x, double y) {return x*y;};
double          div_impl(double x, double y) {if (y==0) avm_error("Division with 0!\n"); return x/y;};
double          mod_impl(double x, double y) {if (y==0) avm_error("Modulo division with 0!\n"); return ((unsigned)x)%((unsigned)y);}
unsigned char   number_tobool(avm_memcell *m){return m->data.numVal!=0;};
unsigned char   string_tobool(avm_memcell *m){return m->data.strVal[0]!=0;};
unsigned char   bool_tobool(avm_memcell *m){return m->data.boolVal;};
unsigned char   table_tobool(avm_memcell *m){return 1;};
unsigned char   userfunc_tobool(avm_memcell *m){return 1;};
unsigned char   libfunc_tobool(avm_memcell *m){return 1;};
unsigned char   nil_tobool(avm_memcell *m){return 0;};
unsigned char   undef_tobool(avm_memcell *m){return 0;};
char*           number_tostring(avm_memcell *m);
char*           string_tostring(avm_memcell *m);
char*           bool_tostring(avm_memcell *m);
char*           table_tostring(avm_memcell *m){return strdup("tableitem");};
char*           userfunc_tostring(avm_memcell *m){return strdup("userfunc");};
char*           libfunc_tostring(avm_memcell *m){return strdup("libfunc");};
char*           nil_tostring(avm_memcell *m){return strdup("nil");};
char*           undef_tostring(avm_memcell *m){return strdup("undef");};
unsigned char   avm_tobool(avm_memcell* m);
bool            jle_impl(double x, double y) { return x <= y; }
bool            jge_impl(double x, double y) { return x >= y; }
bool            jlt_impl(double x, double y) { return x < y; }
bool            jgt_impl(double x, double y) { return x > y; }
void            avm_push_table_arg(avm_table* t);
void            avm_call_functor(avm_table* t);
char*           avm_tostring(avm_memcell* m);
void            avm_calllibfunc(char *id);
library_func_t  avm_getlibraryfunc(char* id);
unsigned        avm_totalactuals();
avm_memcell*    avm_getactual(unsigned i);
void            avm_registerlibfunc(char* id, library_func_t addr);
void            avm_initialize();
void            libfunc_typeof();
void            libfunc_print();
void            libfunc_totalarguments();
void            libfunc_argument();

void            printStack();
void            printStackIndexed(char* type, unsigned index);

unsigned            pc =1;
unsigned            currLine = 0;
unsigned            codeSize = 0;
unsigned            totalGlobals = 0;
unsigned char       executionFinished = 0;
instruction*        code = NULL;
unsigned            totalActuals = 0;

double*             numConsts;
char**              stringConsts;
userFunc*           userFuncs;
char**              libFuncs;

execute_func_t executeFuncs[] = {
    execute_assign,
	execute_add,
	execute_sub,
	execute_mul,
	execute_div,
	execute_mod,
	execute_jump,
	execute_jeq,
	execute_jne,
	execute_jle,
	execute_jge,
	execute_jlt,
	execute_jgt,
	execute_call,
	execute_pusharg,
    execute_funcenter,
    execute_funcexit,
	execute_newtable,
	execute_tablegetelem,
	execute_tablesetelem,
// 	execute_nop
};


library_func_t lib_funcs[] = {
    libfunc_typeof,
    libfunc_print,
    libfunc_totalarguments,
    libfunc_argument
};

memclear_func_t memclearFuncs[] = {
    0,
    memclear_string,
    0,
    memclear_table,
    0,
    0,
    0,
    0
};


arithmetic_func_t arithmeticFuncs[] = {

	add_impl,
	sub_impl,
	mul_impl,
	div_impl,
	mod_impl

};

tobool_func_t toboolFuncs[] = {

	number_tobool,
	string_tobool,
	bool_tobool,
	table_tobool,
	userfunc_tobool,
	libfunc_tobool,
	nil_tobool,
	undef_tobool

};

tostring_func_t tostringFuncs[] = {

	number_tostring,
	string_tostring,
	bool_tostring,
	table_tostring,
	userfunc_tostring,
	libfunc_tostring,
	nil_tostring,
	undef_tostring

};

char* typeStrings[] = {

	"number",
	"string",
	"bool",
	"table",
	"userfunc",
	"libfunc",
	"nil",
	"undef"

};

jump_func_t jumpFuncs[] = {

	jle_impl,
	jge_impl,
	jlt_impl,
	jgt_impl

};


void execute_arithmetic(instruction *instr)
{

	avm_memcell *lv = avm_translate_operand(&instr->result, NULL);
	avm_memcell *rv1 = avm_translate_operand(&instr->arg1, &ax);
	avm_memcell *rv2 = avm_translate_operand(&instr->arg2, &bx);

	ASSERT(lv && (&stack[AVM_STACKSIZE - 1] >= lv && lv >= &stack[top] || lv == &retval));
	ASSERT(rv1 && rv2);

	if (rv1->type != number_m || rv2->type != number_m) {

		avm_error("Arithmetic exception!!\n");
		executionFinished = 1;
	} else {
		arithmetic_func_t op = arithmeticFuncs[instr->opcode - add_v];
		avm_memcellclear(lv);
		lv->type = number_m;
		lv->data.numVal = (*op)(rv1->data.numVal, rv2->data.numVal);
	}
}
void execute_jeq(instruction *instr)
{

	ASSERT(instr->result.type == label_a);

	avm_memcell *rv1 = avm_translate_operand(&instr->arg1, &ax);
	avm_memcell *rv2 = avm_translate_operand(&instr->arg2, &bx);

	unsigned char result = 0;

	if (rv1->type == undef_m || rv2->type == undef_m)
	{
		avm_error("Undefined operation!\n");
		//executionFinished = 1;
	}
    else if (rv1->type == bool_m || rv2->type == bool_m)
	{
       
		result = (avm_tobool(rv1) == avm_tobool(rv2));
        // printf("result: %u\n", result);
	}
	else if (rv1->type == nil_m || rv2->type == nil_m)
	{
		result = (rv1->type == nil_m) && (rv2->type == nil_m);
	}
	else if (rv1->type != rv2->type)
	{
		avm_error("Illegal types!\n");
		//executionFinished = 1;
	}
	else
	{

		if (rv1->type == number_m)
		{
			result = rv1->data.numVal == rv2->data.numVal;
		}
		else if (rv1->type == string_m)
		{
			result = !strcmp(rv1->data.strVal, rv2->data.strVal);
		}
		else
		{
			result = (avm_tobool(rv1) == avm_tobool(rv2));
		}
	}

	if (!executionFinished && result) {
		pc = instr->result.val;
        //printf("pc in jeq: %d\n", pc);
    }
}


void execute_jne(instruction *instr)
{

	ASSERT(instr->result.type == label_a);

	avm_memcell *rv1 = avm_translate_operand(&instr->arg1, &ax);
	avm_memcell *rv2 = avm_translate_operand(&instr->arg2, &bx);

	unsigned char result = 0;

	if (rv1->type == undef_m || rv2->type == undef_m)
	{
		avm_error("Undefined operation!\n");
		//executionFinished = 1;
	}
    else if (rv1->type == bool_m || rv2->type == bool_m)
	{
		result = (avm_tobool(rv1) != avm_tobool(rv2));
	}
	else if (rv1->type == nil_m || rv2->type == nil_m)
	{
		result = (rv1->type != nil_m) || (rv2->type != nil_m);
	}
	
	else if (rv1->type != rv2->type)
	{
		avm_error("Illegal types!\n");
		//executionFinished = 1;
	}
	else
	{

		if (rv1->type == number_m)
		{
			result = rv1->data.numVal != rv2->data.numVal;
		}
		else if (rv1->type == string_m)
		{
			result = strcmp(rv1->data.strVal, rv2->data.strVal);
		}
		else
		{
			result = (avm_tobool(rv1) != avm_tobool(rv2));
		}
	}

	if (!executionFinished && result)
		pc = instr->result.val;
}

void execute_jcomparison(instruction *instr)
{

	avm_memcell *rv1 = avm_translate_operand(&instr->arg1, &ax);
	avm_memcell *rv2 = avm_translate_operand(&instr->arg2, &bx);

    //printf("types: [%d, %d]\n", rv1->type, rv2->type);

	ASSERT(rv1 && rv2);

	if (rv1->type != number_m || rv2->type != number_m)
	{
		avm_error("Jump exception!\n");
		executionFinished = 1;
	}
	else
	{

		jump_func_t cmp = jumpFuncs[instr->opcode - jle_v];
		unsigned char result = (*cmp)(rv1->data.numVal, rv2->data.numVal);

		if (!executionFinished && result)
		{
			pc = instr->result.val;
		}
	}
}

void execute_jump(instruction* instr) {
    ASSERT(instr->result.val!=0);
    if (!executionFinished) {
        //printf("======================> JUMPING TO %d\n", instr->result.val);
        pc = instr->result.val;
    }
}

void execute_assign(instruction* instr) {

   // printf("source line: %d\n", instr->srcLine);
    // printf("pc is : %d\n", pc);
    // printf("result type: %u\n", instr->result.type);
    // printf("arg1 type: %u\n", instr->arg1.type);
    avm_memcell* lv= avm_translate_operand(&instr->result, NULL);
    avm_memcell* rv= avm_translate_operand(&instr->arg1, &ax);
    // printf("assignment to %d\n", instr->result.val);
    // printf("pc is: %d\n", pc);

    // printf("arg1: %d\n", instr->arg1.val);
    // printf("lv is %u\n", lv->type);
    ASSERT(lv && (&stack[AVM_STACKSIZE-1]>=lv && lv >= &stack[top] || lv==&retval));
    ASSERT(rv);

    avm_assign(lv, rv);

    //printf("PRINTING ASSIGN STACK to %d\n", lv-stack);
    //printStackIndexed("assignment",lv-stack);
}

void avm_assign(avm_memcell* lv, avm_memcell* rv) {
    if (lv == rv) return;
    if (lv->type == table_m && rv->type == table_m && lv->data.tableVal == rv->data.tableVal) return;
    if (rv->type == undef_m) avm_warning("assigning from 'undef' content at instruction %d!\n", pc);
    avm_memcellclear(lv);
    //if(rv==&retval)printf("assigning retval to offset %d\n", lv-stack);
    memcpy(lv, rv, sizeof(avm_memcell));
    //printStack();
    //if (rv->type==number_m) printf("result: %f\n", rv->data.numVal);
    if (lv->type == string_m) {
        lv->data.strVal = strdup(rv->data.strVal);
    } else {
        if (lv->type == table_m) {
            avm_tableincrefcounter(lv->data.tableVal);
        }
    }
}

void execute_funcenter(instruction* instr) {

    totalActuals = 0;
    avm_memcell* func = avm_translate_operand(&instr->result, &ax);
    ASSERT(func);
    ASSERT(pc == func->data.funcVal);
    //printf("pc in enter %d\n", pc);
    userFunc* funcInfo = avm_getfuncinfo(instr->result.val);
    topsp = top;
    //printf("total Actuals %d\n", totalActuals);
    
    //funcInfo->localSize++;
    //printf("localsize %d\n", funcInfo->localSize);
    top = top - funcInfo->localSize;
}

unsigned avm_get_ennvalue(unsigned i) {
    ASSERT(stack[i].type == number_m);
    //printf("stack[i].data.numVal is: %f\n", stack[i].data.numVal);
    if (stack[i].data.numVal < 0) avm_error("Negative value in 'argument!\n");
    unsigned val = (unsigned)stack[i].data.numVal;
    //printf("val is: %f\n", (double)val);
    ASSERT(stack[i].data.numVal==((double) val));
    return val;
}

void execute_funcexit(instruction* unused) {

    unsigned oldTop = top;
    top = avm_get_ennvalue(topsp + AVM_SAVEDTOP_OFFSET);
    pc = avm_get_ennvalue(topsp + AVM_SAVEDPC_OFFSET);
    topsp = avm_get_ennvalue(topsp + AVM_SAVEDTOPSP_OFFSET);

    while (++oldTop <= top) {
        avm_memcellclear(&stack[oldTop]);
    }
}

void execute_call(instruction* instr) {
    //printf("type in call %d\n", instr->arg1.type);
    avm_memcell* func = avm_translate_operand(&instr->arg1, &ax);
    //printf("type in call %d\n", instr->arg1.type);
    //printf("AFTER TRANSLATE IN CALL\n");
    char* s;
    ASSERT(func);
    switch (func->type) {
        case userfunc_m: 
            avm_callsaveenviroment();
            pc = func->data.funcVal;
            ASSERT(pc < AVM_ENDING_PC);
            ASSERT(code[pc].opcode == funcenter_v);
            break;
        case string_m: avm_calllibfunc(func->data.strVal); break;
        case libfunc_m: /*printf("calling lib function %s\n", func->data.libfuncVal);*/ avm_callsaveenviroment(); avm_calllibfunc(func->data.libfuncVal); break;
        case table_m: avm_call_functor(func->data.tableVal); break;
        default:
            s = avm_tostring(func);
            avm_error("call: cannot bind [%s] to function!\n", s);
            free(s);
            executionFinished = 1;
    }

    //printStack();
}

unsigned avm_totalactuals() {
    return avm_get_ennvalue(topsp + AVM_NUMACTUALS_OFFSET);
}

avm_memcell* avm_getactual(unsigned i) {
    ASSERT(i < avm_totalactuals());
    return &stack[topsp + AVM_STACKENV_SIZE + 1 + i];
}

char* bool_tostring(avm_memcell* m) {
    ASSERT(m->type==bool_m);
    if (m->data.boolVal == '0') {
        return strdup("false");
    } else {
        return strdup("true");
    }
}

char* removeStringLiterals(char* str){
    char* s = strdup(str);
    s[strlen(s)-1] = '\0';
    return s+1;
}

char* string_tostring(avm_memcell* m) {
    //printf("string is %s\n", m->data.strVal);
    ASSERT(m->type==string_m);
    return m->data.strVal;
}

char* number_tostring(avm_memcell* m) {
    ASSERT(m->type==number_m);
    return num_to_str(m->data.numVal);
}

char* avm_tostring(avm_memcell* m) {
    ASSERT(m->type >= 0 && m->type<=undef_m);
    //printf("type in avmtostring %d\n", m->type);
    return (*tostringFuncs[m->type])(m);
}

void avm_call_functor(avm_table* t) {
    cx.type = string_m;
    cx.data.strVal = "()";
    avm_memcell* f = avm_tablegetelem(t, &cx);
    if (!f) avm_error("In calling table: no '()' element found!\n");
    else {
        if (f->type==table_m) {
            avm_call_functor(f->data.tableVal);

        } else {
            if (f->type==userfunc_m) {
                avm_push_table_arg(t);
                avm_callsaveenviroment();
                pc = f->data.funcVal;
                ASSERT(pc < AVM_ENDING_PC && code[pc].opcode==funcenter_v);
            } else {
                //printf("type in functor %d\n", f->type);
                avm_error("In calling table: illegal '()' element value!\n");
            }
        }
    }
}

void avm_push_table_arg(avm_table* t) {
    stack[top].type = table_m;
    avm_tableincrefcounter(stack[top].data.tableVal=t);
    ++totalActuals;
    avm_dec_top();
}

void execute_pusharg(instruction* instr) {
    //printf("instr arg data is %u\n", instr->);
    //printf("instr arg type is %d\n", instr->arg1.type);
    avm_memcell* arg = avm_translate_operand(&instr->arg1, &ax);
    ASSERT(arg);
    avm_assign(&stack[top], arg);
    stack[top].info = "Argument";
    ++totalActuals;
    //printf("------TOTAL ACTUALS IS NOW %d\n", totalActuals);
    avm_dec_top();
    //printStack();
}

unsigned char avm_tobool(avm_memcell* m) {
    ASSERT(m->type >=0 && m->type < undef_m);
    return (*toboolFuncs[m->type])(m);
}

void avm_dec_top() {
    if (!top) {
        avm_error("stack overflow!!\n");
        executionFinished = 1;
    } else {
        --top;
    }
}

void avm_push_ennvalue(unsigned val) {
    stack[top].type = number_m;
    stack[top].data.numVal = val;
    //printf("in push val is %u\n", val);
    avm_dec_top();
}

void avm_callsaveenviroment() {
    stack[top].info = "Total actuals";
    avm_push_ennvalue(totalActuals);
    ASSERT(code[pc].opcode == call_v);
    stack[top].info = "Old pc + 1";
    avm_push_ennvalue(pc + 1);
    stack[top].info = "Top + totalActuals + 2";
    avm_push_ennvalue(top + totalActuals + 2);
    stack[top].info = "Topsp";
    avm_push_ennvalue(topsp);
}




void avm_calllibfunc(char *id) {

	library_func_t f = avm_getlibraryfunc(id);
    // printf("f is %p\n", f);
    // printf("typeof is %p\n", libfunc_typeof);
	if (!f) {
		avm_error("Unsupported libfunc %s called!\n", id);
		executionFinished = 1;
	}
	else {
		topsp = top;
        //printf("topsp in calllibfunc is %u\n", topsp);
        //printf("stack[topsp+3] after topsp=top: %f\n", stack[topsp+4].data.numVal);
		totalActuals = 0;
        //printf("before call!\n");
		(*f)();
		if (!executionFinished) { // if it's 0
            //printf("HERE\n");
			execute_funcexit(NULL);
		}
        //printf("ok libfunc!\n");
	}
}

library_func_t  avm_getlibraryfunc(char* id) {
    //printf("HERE\n");
    if (strcmp(id, "print")==0) return libfunc_print;
    else if (strcmp(id, "totalarguments")==0) return libfunc_totalarguments;
    else if (strcmp(id, "typeof")==0) return libfunc_typeof;
    else if (strcmp(id, "argument")==0) return libfunc_argument;
    return 0;

}

void printStack(){
    printf("=============START OF STACK PRINT============\n");
    for(unsigned i = AVM_STACKSIZE-1; i>top;i--){
        if(stack[i].type<0||stack[i].type>undef_m)continue;
        printf("============================\n");
        printf("|[OFFSET:%4d][%4d]%7s|", AVM_STACKSIZE-i-1, i, avm_tostring(&stack[i].data));
        if(i>=AVM_STACKSIZE-12){
            PRINT_RED(" <-- LIBRARY FUNCTION");
        }
        
        if(stack[i].info!=NULL)PRINT_YELLOW(" [%s]\n", stack[i].info);

        printf("\n");
    }
    printf("[RETURN REGISTER: %s]\n", avm_tostring(&retval.data));
    printf("=============END OF STACK PRINT============\n");
}

void printStackIndexed(char* type, unsigned index){
    printf("=============START OF STACK PRINT============\n");
    for(unsigned i = AVM_STACKSIZE-1; i>top;i--){
        if(stack[i].type<0||stack[i].type>undef_m)continue;
        printf("============================\n");
        printf("|[OFFSET:%4d][%4d]%7s|", AVM_STACKSIZE-1-i, i, avm_tostring(&stack[i].data));

        if(i>=AVM_STACKSIZE-12){
            PRINT_RED(" <-- LIBRARY FUNCTION");
        }else if(index==i){
            printf(" <------ Accessed [%s] at pc %u", type, pc);
        }

        if(stack[i].info!=NULL)PRINT_YELLOW(" [%s]\n", stack[i].info);

        printf("\n");
    }
    printf("[RETURN REGISTER: %s]\n", avm_tostring(&retval.data));
    printf("=============END OF STACK PRINT============\n");
}

void libfunc_print() {
    //printStack();
    //printf("total actuals in print %u\n", totalActuals);
    unsigned n = avm_totalactuals();
    //printf("n IN PRINT %u\n", n);
    for (unsigned i=0; i < n; ++i) {
        char* s = avm_tostring(avm_getactual(i));
        //printf("===================\n");
        printf("%s", s);
        //printf("===================\n");
        free(s);
        
    }
    printf("\n");
}



void libfunc_typeof() {
    unsigned n = avm_totalactuals();
    if (n!=1) {
       avm_error("one argument expected in typeof!\n"); 
       executionFinished = 1;
    } else {
        avm_memcellclear(&retval);
        retval.type = string_m;
        //printf("typeof got %s\n", avm_tostring(&avm_getactual(0)->data));
        retval.data.strVal = strdup(typeStrings[avm_getactual(0)->type]);
    }

    //printStack();
}

void libfunc_totalarguments() {
	unsigned int p_topsp = avm_get_ennvalue(topsp + AVM_SAVEDTOPSP_OFFSET);
	avm_memcellclear(&retval);
	if (!p_topsp) {
		avm_error("'totalarguments' called outside a function!\n");
		retval.type = nil_m;
	}
	else {
		retval.type = number_m;
		retval.data.numVal = avm_get_ennvalue(p_topsp + AVM_NUMACTUALS_OFFSET);
	}
}

void libfunc_argument() {
    unsigned int p_topsp = avm_get_ennvalue(topsp + AVM_SAVEDTOPSP_OFFSET);
    avm_memcellclear(&retval);
    if (!p_topsp) {
        avm_error("'argument' called outside a function!\n");
        retval.type = nil_m;
    } else {
        
        unsigned int args = avm_totalactuals(); // of argument(i)
        //printf("total actuals is %u\n", args);
        unsigned int func_args = avm_get_ennvalue(p_topsp + AVM_NUMACTUALS_OFFSET);
        if (args!=1) {
            avm_error("One argument expected in 'argument'!\n");
            retval.type = nil_m;
        } else {
            unsigned int index = avm_get_ennvalue(topsp + AVM_SAVEDTOPSP_OFFSET + sizeof(index));

            if (func_args <= index) {
                avm_error("Index out of range!\n");
            }
            unsigned int arg_address = p_topsp + AVM_STACKENV_SIZE + 1 + index;
            // printf("arg address: %d\n", arg_address);
            // printStackIndexed("argument", arg_address);
            avm_assign(&retval, &stack[arg_address]);
        }
        
        // if (index-1 >= avm_totalactuals()) {
        //     avm_error("Argument index %u out of range (only %u arguments available)", index, avm_totalactuals());
            
        // } else {
        //     avm_memcell* arg = avm_getactual(index-1);
        //     avm_assign(&retval, arg);
        // }
    }
}

avm_memcell* avm_translate_operand(vmarg* arg, avm_memcell* reg) {
    //printf("type is in translate: %u\n", arg->type);
    switch(arg->type) {

        case global_a: /*printf("at pc %d: accessing global at offset %d\n", pc, arg->val);*/ /*printStackIndexed("global", AVM_STACKSIZE-arg->val);*/ return &stack[AVM_STACKSIZE-arg->val]; //was AVM_STACKSIZE-1-arg->val
        case local_a:  /*printStackIndexed("local", topsp-arg->val);*/ return &stack[topsp-arg->val];
        case formal_a: /*printStackIndexed("formal", topsp+AVM_STACKENV_SIZE+1+arg->val);*/ return &stack[topsp+AVM_STACKENV_SIZE+1+arg->val]; 
        case retval_a: return &retval;
        case number_a:
            reg->type = number_m;
            reg->data.numVal = consts_getnumber(arg->val);
            return reg;
        case string_a:
            reg->type = string_m;
            reg->data.strVal = consts_getstring(arg->val);
            return reg;
        case bool_a:
            reg->type = bool_m;
            reg->data.boolVal = arg->val;
            return reg;
        case nil_a: reg->type = nil_m; return reg;
        case userfunc_a:
            reg->type = userfunc_m;
            //printf("arg val %u\n", arg->val);
            if(((int)arg->val)==-1){
                avm_error("Attempting to call an undefined function\n");
            }
            reg->data.funcVal = avm_getfuncinfo(arg->val)->address;
            return reg;
        case libfunc_a: 
            reg->type = libfunc_m;
            reg->data.libfuncVal = libfuncs_getused(arg->val);
            return reg;
        default:
            printf("FAILED AT INSTRUCTION #%d\n", pc);
            ASSERT(0);
    }
}

double consts_getnumber(unsigned int val) {
    ASSERT(val>=0);
    return numConsts[val];
}

char* consts_getstring(unsigned int val) {
    ASSERT(val>=0);
    return stringConsts[val];
}

char* libfuncs_getused(unsigned int val) {
    ASSERT(val>=0);
    return libFuncs[val];
}

userFunc* avm_getfuncinfo(unsigned int val) {
    ASSERT(val>=0);
    //printf("in getinfo val %u\n", val);
    return &(userFuncs[val]);
}

void avm_initstack() {
    for (unsigned int i=0; i < AVM_STACKSIZE; ++i) {
        AVM_WIPEOUT(stack[i]);
        stack[i].type=undef_m;
    }
}

void avm_tableincrefcounter(avm_table* t) {
    ++t->refCounter;
}

void avm_tabledecrefcounter(avm_table* t) {
    ASSERT(t->refCounter);
    if (!(--t->refCounter)) {
        avm_tabledestroy(t);
    }
}

void avm_tablebucketsinit(avm_table_bucket** p) {
    for (unsigned int i=0; i < AVM_TABLE_HASHSIZE; ++i) {
        p[i] = NULL;
    }
}


int avm_hash(char* key){ /* key= identifier name*/
    ASSERT(key!=NULL);
    
    int sum=0,i,temp;

    size_t key_len = strlen(key);

    for(i=0;i<key_len;i++){
        temp=key[i]; //first we do assign to int value then we use it
        sum+=temp;
    }

    return abs((sum)%AVM_TABLE_HASHSIZE);  /* se apolyth timh gia na apofeugw tis arnhtikes times*/
}

void execute_newtable(instruction* instr) {
     avm_memcell* lv = avm_translate_operand(&instr->arg1, NULL);
     ASSERT(lv && &stack[AVM_STACKSIZE-1] >= lv && lv >= &stack[top] || lv == &retval);
     avm_memcellclear(lv);
     lv->type=table_m;
     lv->data.tableVal=avm_tablenew();
     avm_tableincrefcounter(lv->data.tableVal);
}

void execute_tablegetelem(instruction* instr) {
    avm_memcell* lv = avm_translate_operand(&instr->result, NULL);
    avm_memcell* t = avm_translate_operand(&instr->arg1, NULL);
    avm_memcell* i = avm_translate_operand(&instr->arg2, &ax);

    ASSERT(lv && &stack[AVM_STACKSIZE-1] >= lv && lv >= &stack[top] || lv == &retval);
    ASSERT(t && &stack[AVM_STACKSIZE-1] >= t && t >= &stack[top]);
    ASSERT(i);

    avm_memcellclear(lv);
    lv->type=nil_m;
    if(t->type!=table_m){
        avm_error("arg1 in get not a table\n");
    }else {
        avm_memcell* content = avm_tablegetelem(t->data.tableVal, i);
        if (content) avm_assign(lv, content);
        else {
            char* ts = avm_tostring(t);
            char* is  = avm_tostring(i);
            avm_error("Element '%s' of table '%s' not found!\n", is, ts);
            free(ts);
            free(is);
        }
        
    }
}

void execute_tablesetelem(instruction* instr) {
    avm_memcell* t = avm_translate_operand(&instr->arg1, NULL);
    avm_memcell* i = avm_translate_operand(&instr->arg2, &ax);
    avm_memcell* c = avm_translate_operand(&instr->result, &bx);

    ASSERT(t && &stack[AVM_STACKSIZE-1] >= t && t >= &stack[top]);
    ASSERT(i && c);

    if (t->type != table_m) {
        avm_error("Illegal use of type as table!\n");
    } else {
        avm_tablesetelem(t->data.tableVal, i, c);
    }
}

avm_table* avm_tablenew() {
    avm_table* t =(avm_table*)safe_malloc(sizeof(avm_table));
    AVM_WIPEOUT(*t);

    t->refCounter = t->total =0;
    avm_tablebucketsinit(t->numIndexed);
    avm_tablebucketsinit(t->strIndexed);

    return t;
}

avm_memcell *avm_tablegetelem(avm_table *table, avm_memcell *index) {

	ASSERT(table);

	int hash_index;
	if (index->type == string_m) {

		hash_index = avm_hash(index->data.strVal);

		if (table->strIndexed[hash_index] != NULL) {
			avm_table_bucket *bucket = table->strIndexed[hash_index];
			while (bucket != NULL) {
				if (streq(bucket->key.data.strVal, index->data.strVal))
					return &bucket->value;

				bucket = bucket->next;
			}
		}
	}
	else if (index->type == number_m) {

		hash_index = (int)index->data.numVal % AVM_TABLE_HASHSIZE;

		if (table->numIndexed[hash_index] != NULL) {
			avm_table_bucket *bucket = table->numIndexed[hash_index];
			while (bucket != NULL) {
				if (bucket->key.data.numVal == index->data.numVal)
					return &bucket->value;

				bucket = bucket->next;
			}
		}
	}
	return NULL;
}

void avm_tablesetelem(avm_table *table, avm_memcell *index, avm_memcell *content)
{

	ASSERT(table);

	int hash_index;

	avm_memcell *table_item = avm_tablegetelem(table, index);

	if (index->type == string_m) {

		hash_index = avm_hash(index->data.strVal);

		if (table_item != NULL) {
			avm_assign(table_item, content);
			return;
		}

		if (table->strIndexed[hash_index] == NULL) {


			table->strIndexed[hash_index] = (avm_table_bucket *)safe_malloc(sizeof(avm_table_bucket));

			table->strIndexed[hash_index]->key = *index;

            //printf("INDEX STRING:%s \n",table->strIndexed[hash_index]->key.data.strVal);

			if (content->type == table_m) {
				avm_tableincrefcounter(content->data.tableVal);
			}

			table->strIndexed[hash_index]->value = *content;

			table->strIndexed[hash_index]->next = NULL;
			table->total++;

			return;
		}

		avm_table_bucket *temp = table->strIndexed[hash_index];
		while (temp->next != NULL) {
			temp = temp->next;
		}

		avm_table_bucket *bucket = (avm_table_bucket *)safe_malloc(sizeof(avm_table_bucket));
		bucket->key = *index;
        //printf("INDEX STRING:%s \n",table->strIndexed[hash_index]->key.data.strVal);

		if (content->type == table_m)
		{
			avm_tableincrefcounter(content->data.tableVal);
		}

		bucket->value = *content;
		temp->next = bucket;
		bucket->next = NULL;
		table->total++;
	}
	else if (index->type == number_m)
	{

		hash_index = (int)index->data.numVal % AVM_TABLE_HASHSIZE;

		if (table_item != NULL)
		{
			avm_assign(table_item, content);
			return;
		}

		if (table->numIndexed[hash_index] == NULL)
		{

			table->numIndexed[hash_index] = (avm_table_bucket *)safe_malloc(sizeof(avm_table_bucket));
			table->numIndexed[hash_index]->key=*index;
        
            //printf("INDEX NUMBER:%f \n",table->numIndexed[hash_index]->key.data.numVal);

			if (content->type == table_m)
			{
				avm_tableincrefcounter(content->data.tableVal);
			}

			table->numIndexed[hash_index]->value = *content;

			table->numIndexed[hash_index]->next = NULL;
			table->total++;

			return;
		}

		avm_table_bucket *temp = table->numIndexed[hash_index];
		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		avm_table_bucket *bucket = (avm_table_bucket *)safe_malloc(sizeof(avm_table_bucket));
		bucket->key = *index;
        //printf("INDEX NUMBER:%f \n",bucket->key.data.numVal);

        bucket->key.type=number_m;

		if (content->type == table_m)
		{
			avm_tableincrefcounter(content->data.tableVal);
		}

		bucket->value = *content;
		temp->next = bucket;
		bucket->next = NULL;
		table->total++;
	}
}

void avm_tabledestroy(avm_table* t) {
    avm_tablebucketdestroy(t->strIndexed);
    avm_tablebucketdestroy(t->numIndexed);
    free(t);
}

void avm_tablebucketdestroy(avm_table_bucket** p) {
    for (unsigned int i=0; i < AVM_TABLE_HASHSIZE ; ++i) {
        avm_table_bucket* b = p[i];
        while (b) {
            avm_table_bucket* del = b;
            b = b->next;
            avm_memcellclear(&del->key);
            avm_memcellclear(&del->value);
            free(del);
            
        }
        
        p[i]=NULL;
    }
}

void avm_memcellclear(avm_memcell* m) {
    // printf("TYPEEE %u \n",m->type);
    if (m->type!=undef_m) {
        memclear_func_t f = memclearFuncs[m->type];
        if (f) {
            (*f)(m);
        }
        m->type = undef_m;
    }
}

void memclear_string(avm_memcell* m) {
    ASSERT(m->data.strVal);
    //free(m->data.strVal);
}

void memclear_table(avm_memcell* m) {
    ASSERT(m->data.tableVal);
    avm_tabledecrefcounter(m->data.tableVal);
}

int getNextInt(FILE* file){
    ASSERT(file);
    int num;
    int res = fread(&num, sizeof(num), 1, file);

    if(res==EOF&&res==-1){
        ERR_CORRUPT_FILE();
        exit(EXIT_FAILURE);
    }

    return num;
}

double getNextDouble(FILE* file){
    ASSERT(file);
    double num;
    int res = fread(&num, sizeof(num), 1, file);

    if(res==EOF&&res==-1){
        ERR_CORRUPT_FILE();
        exit(EXIT_FAILURE);
    }

    return num;
}

unsigned getNextUnsigned(FILE* file){
    ASSERT(file);
    unsigned num;
    int res = fread(&num, sizeof(num), 1, file);

    if(res==EOF&&res==-1){
        ERR_CORRUPT_FILE();
        exit(EXIT_FAILURE);
    }

    return num;
}

char* getNextString(FILE* file, unsigned length){
    ASSERT(file);
    ASSERT(length>0);

    char* str = (char*)safe_malloc(length+1);
    int res = fread(str, sizeof(char), length, file);
    str[length] = '\0';

    if(res==EOF&&res==-1){
        ERR_CORRUPT_FILE();
        exit(EXIT_FAILURE);
    }

    return str;
}

void loadBinaryFile(FILE* file){
    unsigned no_numbers = getNextUnsigned(file);
    numConsts = (double*)safe_malloc(no_numbers*sizeof(double));
    for(int i=0;i<no_numbers;i++){
        numConsts[i] = getNextDouble(file);
    }
    
    unsigned no_strings = getNextUnsigned(file);
    stringConsts = (char**)safe_malloc(no_strings*sizeof(char*));
    for(int i=0;i<no_strings;i++){
        int len = getNextInt(file);
        stringConsts[i] = removeStringLiterals(getNextString(file, len));
    }

    unsigned no_userfuncs = getNextUnsigned(file);
    userFuncs = (userFunc*)safe_malloc(no_userfuncs*sizeof(userFunc));
    for(int i=0;i<no_userfuncs;i++){
        userFuncs[i].address = getNextUnsigned(file);
        userFuncs[i].localSize = getNextUnsigned(file)+1;
        //printf("localsize in load i:%d %u\n",i, userFuncs[i].localSize);
        int len = getNextInt(file);
        userFuncs[i].id = getNextString(file, len);
    }

    unsigned no_libfuncs = getNextUnsigned(file);
    libFuncs = (char**)safe_malloc(no_libfuncs*sizeof(char*));
    for(int i=0;i<no_libfuncs;i++){
        int len = getNextInt(file);
        libFuncs[i] = getNextString(file, len);
    }
    totalGlobals = getNextInt(file);
    //printf("total globals is %d\n", totalGlobals);
    codeSize = getNextUnsigned(file);
    code = (instruction*)safe_malloc(codeSize*sizeof(instruction));

    for(int i=1;i<codeSize;i++){
        code[i].srcLine = getNextInt(file);
        code[i].opcode = getNextInt(file);
        code[i].arg1.type = getNextInt(file);
        // printf("type a1 is %u:\n", code[i].arg1.type);
        code[i].arg1.val = getNextInt(file);
        code[i].arg2.type = getNextInt(file);
        code[i].arg2.val = getNextInt(file);
        code[i].result.type = getNextInt(file);
        code[i].result.val = getNextInt(file);
        //printf("[%2i]: result-> %3d\n", i, code[i].result.val);
    }

    printf("Binary file loaded successfully...\n");
    printf("Running...\n");
}

void execute_cycle(void){
    //printStack();

    if(executionFinished){
        return;
    }else if(pc==AVM_ENDING_PC){
        //printf("IN PC\n");
        executionFinished = 1;
        return;
    }else{
        ASSERT(pc<AVM_ENDING_PC);
        instruction* instr = code + pc;
        ASSERT(
            instr->opcode>=0&&
            instr->opcode<=AVM_MAX_INSTRUCTIONS
        );
        if(instr->srcLine)
            currLine = instr->srcLine;

        unsigned oldPC = pc;
        //printf("opcode: %d\n", instr->opcode);
        (*executeFuncs[instr->opcode])(instr);

        if(pc==oldPC)
            ++pc;
        }
}
