/**
 * @file alpha_bison_utilities.h
 *
 * Utility library for the implementation of the alpha
 * syntax analyzer.
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
 * @date 25/3/2024
*/


#ifndef ALPHA_BISON_UTILITIES_H

#define ALPHA_BISON_UTILITIES_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "alpha_definitions.h"
#include "alpha_general_types.h"
#include "alpha_general_utilities.h"
#include "alpha_stack.h"

#define SYMTABLE_NUM_BUCKETS 256
#define UNIVERSAL_HASH_P 257
#define EXPAND_SIZE 1024
#define CURR_SIZE (total_quads * sizeof(quad))
#define NEW_SIZE (EXPAND_SIZE * sizeof(quad) + CURR_SIZE)

//Expression utilities
#define assign_expr_int(expr, val)\
    (expr).type = EXPR_TYPE_INT,(expr).value.intVal = val

#define assign_expr_real(expr, val)\
    (expr).type = EXPR_TYPE_REAL,(expr).value.realVal = val

#define assign_expr_str(expr, val)\
    (expr).type = EXPR_TYPE_STR,(expr).value.stringVal = val

#define get_expr_int(expr)\
    ((expr).value.intVal)

#define get_expr_real(expr)\
    ((expr).value.realVal)

#define get_expr_str(expr)\
    ((expr).value.stringVal)    

#define scope_increase()\
    scope_var++,check_max_scope()

#define scope_decrease()\
    scope_var--


#define increase_loop_counter()\
    loop_counter++

#define decrease_loop_counter()\
    loop_counter--

#define return_loop_counter()\
    (loop_counter)

#define increase_in_func_block_counter()\
    in_func_block++

#define decrease_in_func_block_counter()\
    in_func_block--

#define return_in_func_block_counter()\
    (in_func_block)

#define isTypeVariable(type) \
    ((type)==TYPE_GLOBAL||(type)==TYPE_FORMAL||(type)==TYPE_LOCAL)

#define resetfunctionlocalsoffset()\
   functionlocalsoffset=-1

#define get_global_vars()\
    (global_offset)

#define resetfunctionformalsoffset()\
    functionformalsoffset=0;

#define get_total_formal_args()\
    (functionformalsoffset)

#define get_total_local_vars()\
    (functionlocalsoffset)


#define decrease_functionformalsoffset()\
    functionformalsoffset--


#define decrease_functionlocalsoffset()\
    functionlocalsoffset--


#define set_local_var(size)\
    functionlocalsoffset=size

#define set_formal_offset(size)\
    functionformalsoffset=size

#define INVALID_BOOL -1

extern char* in_filename;

enum SymbolType {
    TYPE_GLOBAL, TYPE_LOCAL, TYPE_FORMAL,  TYPE_USERFUNC, TYPE_LIBFUNC
};

enum SymbolSpace {
    PROGRAMVAR, FUNCTIONLOCAL, FORMALARG
};

extern void* safe_malloc(size_t);

//=======Declarations=======//
typedef struct Variable         Variable_t;
typedef struct Function         Function_t;
typedef struct SymbolTableEntry SymbolTableEntry_t;
typedef struct SymTable_Bucket  SymTable_Bucket_t;
typedef struct SymbolTable     *SymbolTable_t;
typedef struct SymTable_Element SymTable_Element_t;
typedef struct Expr_Type        Expr_Type_t;
typedef struct Funcstack_elem   *Funcstack_elem_t;
typedef struct Funcstack        *Funcstack_t;
typedef struct Entry_stack_elem *Entry_stack_elem_t;
typedef struct Entry_stack      *Entry_stack_t;
typedef enum   iopcode           iopcode;
typedef enum   expr_t            expr_t;
typedef struct expr              expr;
typedef struct quad              quad;
// typedef struct Quad_list_node    *Quad_list_node_t;
// typedef struct Quad_list         *Quad_list_t;
typedef struct stmt_t            stmt_t;


SymbolTable_t       new_SymbolTable();
void                SymbolTable_insert_local(SymbolTable_t symtable, SymbolTableEntry_t* entry, bool isAssignment);
void                SymbolTable_insert(SymbolTable_t symtable, SymbolTableEntry_t* entry, bool isAssignment);
void                SymbolTable_insert_scoped(SymbolTable_t symtable, SymbolTableEntry_t* entry, bool local, bool isAssignment);
SymbolTableEntry_t* SymbolTable_lookup(SymbolTable_t symtable, char* key,bool isTemp);
SymbolTableEntry_t* SymbolTable_lookup_global(SymbolTable_t symtable, char* key);
void                symtable_bucket_insert(SymTable_Bucket_t* bucket, SymbolTableEntry_t* entry);
SymbolTableEntry_t* symtable_bucket_lookup(SymTable_Bucket_t* bucket, char* key, long int scope, bool local, bool allow_shadowing,bool isTemp);
bool                expr_to_bool(Expr_Type_t expr);
SymbolTableEntry_t* new_SymbolTableVariable(char* name);
SymbolTableEntry_t* new_SymbolTableFormalVariable(char* name);
SymbolTableEntry_t* new_SymbolTableFunction(char* name);
SymbolTableEntry_t* new_SymbolTableEntry(char* name, int function);
void                SymbolTable_require(SymbolTable_t symtable, char* key);
void                SymbolTable_require_global(SymbolTable_t symtable, char* key);
char*               newAnonymousFunction();
enum SymbolType     getScope(SymbolTableEntry_t* entry);
char*               typeToString(enum SymbolType type);
char*               expr_to_string(expr* e);
SymbolTableEntry_t* newTemp();
expr*               new_Expr(expr_t type);
void                Check_type(expr* x);
expr*               new_conststring(char* str);
void                reset_counter_temp();
expr*               make_call(expr* lv, expr* reversed_elist);
char*               addStringLiterals(char* str);
struct Quad_list_node* new_Quad_list_node(int _value);
void                   delete_Quad_list_node(struct Quad_list_node* obj);
struct Quad_list*      new_Quad_list();
void                   delete_Quad_list(struct Quad_list* obj);
void                   increase_globaloffset();
void                   increase_functionformalsoffset();
void                   increase_functionlocalsoffset();
bool                   Funcstack_isempty(Stack_t stack);
void                   SymbolTable_delete(SymbolTable_t symtable, char* key);
bool                   isConstant(expr* e);
void SymbolTable_insert_temp(SymbolTable_t symtable, SymbolTableEntry_t* entry);
SymbolTableEntry_t* SymbolTable_lookup_local(SymbolTable_t symtable, char* key);

//==========================//


Stack_t          pfunc_jumpstack;
unsigned int scope_var;
unsigned int scope_offset = 0;
unsigned int max_scope;
extern int yylineno;
SymbolTable_t symbol_table;
Stack_t scope_stack;
Stack_t formal_args_stack;
Stack_t local_args_stack;
Stack_t loop_count_stack;
Stack_t in_func_block_stack;
quad* quads = NULL;
unsigned int total_quads = 1;
unsigned int curr_quad = 1;
unsigned int loop_counter = 0;
unsigned int in_func_block = 0;
int inner_counter_for_temp=1;
int total_new_temps_used_in_stmt=0;
int remain_available_temps=0;
int functionlocalsoffset = -1;
int functionformalsoffset=0;
int global_offset=0;
Stack_t loop_stack;
bool error_found = false;
Funcstack_t      funcstack;

/* @param m Size of the hash table.
 * @param p Prime number for the universal hash functions.*/

int Universal_Hash(int m,int p,char* key){ /* key= identifier name*/
    ASSERT(key!=NULL);
    
    int sum=0,i,temp;

    size_t key_len = strlen(key);

    for(i=0;i<key_len;i++){
        temp=key[i]; //first we do assign to int value then we use it
        sum+=temp;
    }

    return abs(((sum)%p)%m);  /* se apolyth timh gia na apofeugw tis arnhtikes times*/
}

void check_max_scope(){\
    if(scope_var>max_scope){
        max_scope = scope_var;
    }
}

char* newAnonymousFunction() {
    static int counter=1;
    double counter_len;
    char* name;
     counter_len = log10((double)counter)+1;

    name = safe_malloc((int)counter_len*sizeof(char*));

    sprintf(name, "$%d", counter);

    counter++;

    return name;

}

enum ScopeType {
    SCOPE_GLOBAL, SCOPE_FORMAL, SCOPE_BLOCK, SCOPE_FUNCTIONAL
};

void enter_scope_offset(enum ScopeType scope_type){
    switch (scope_type)
    {
    case SCOPE_FUNCTIONAL:
        Stack_push(scope_stack, true);
        break;
    case SCOPE_BLOCK:
        Stack_push(scope_stack, false);
        break;
    
    default:
        break;
    }
}



void exit_scope_offset(){
    Stack_pop(scope_stack);
}

enum ScopeType check_scope_offset(){
    return Stack_peek(scope_stack);
}

struct Variable {
    char *name;
    unsigned int scope;
    unsigned int line;
    unsigned int offset;
};

struct Function {
    char *name;
    //List of arguments
    unsigned int scope;
    unsigned int line;
    unsigned int offset;
    unsigned int iaddress;
    unsigned int taddress;
    unsigned int totalArgs;
    unsigned int totalLocals;
    retlist *retlist;
    
};

struct SymbolTableEntry { 
    
    bool isActive;
    bool isTable;
    union{
        Variable_t *varVal;
        Function_t *funcVal;
    }value;
    enum SymbolType type;
    enum SymbolSpace space;

};

/**
 * Implementation of a regular fixed-size hash-table,
 * using linked-lists within buckets.
*/
struct SymTable_Element{
    SymbolTableEntry_t* entry;
    struct SymTable_Element* next;
};

struct SymTable_Bucket{
    SymTable_Element_t* head;
    size_t length;
};

struct SymbolTable{
    SymTable_Bucket_t* hashTable;
    size_t num_buckets;
};


struct Funcstack_elem {
    Function_t* value;
    Funcstack_elem_t next;
};

struct Funcstack {
    Funcstack_elem_t top;
    int size;
};

bool Funcstack_isempty(Stack_t stack) {
    return stack->size==0;
}


Funcstack_elem_t new_Funcstack_elem(Function_t* _value){
    Funcstack_elem_t new_obj = (Funcstack_elem_t)safe_malloc(sizeof(struct Funcstack_elem));
    new_obj->value = _value;
    return new_obj;
}

void delete_Funcstack_elem(Funcstack_elem_t obj){
    free(obj);
}

Funcstack_t new_Funcstack(){
    Funcstack_t new_obj = (Funcstack_t)safe_malloc(sizeof(struct Funcstack));
    new_obj->top = NULL;
    new_obj->size = 0;
    return new_obj;
}


void Funcstack_push(Funcstack_t stack, Function_t* val){
    Funcstack_elem_t new_elem = new_Funcstack_elem(val);
    new_elem->next = stack->top;
    stack->top = new_elem;
    stack->size++;
}

Function_t* Funcstack_pop(Funcstack_t stack){
    if(stack->size>0){
        stack->size--;
        Funcstack_elem_t old_top = stack->top;
        Function_t* old_val = old_top->value;
        stack->top = stack->top->next;
        delete_Funcstack_elem(old_top);
        return old_val;
    }
    ERROR("Attempting to pop empty stack!\n");
}


Function_t* Funcstack_peek(Funcstack_t stack){
    if(stack->size>0){
        return stack->top->value;
    }
    ERROR("Attempting to peek empty stack!\n");
}

struct Entry_stack_elem {
    SymbolTableEntry_t value;
    Entry_stack_elem_t next;
};

struct Entry_stack {
    Entry_stack_elem_t top;
    int size;
};

SymbolTableEntry_t Entry_stack_lookup(Entry_stack_t stack, int index){
    if(stack->size>0&&stack->size>index){
        Entry_stack_elem_t current_elem = stack->top;
        for(int i=stack->size-1;i>index;i--){
            current_elem = current_elem->next;
        }
        return current_elem->value;
    }
    ERROR("Out-of-bounds lookup index for stack!\n");
}

Entry_stack_elem_t new_Entry_stack_elem(SymbolTableEntry_t _value){
    Entry_stack_elem_t new_obj = (Entry_stack_elem_t)safe_malloc(sizeof(struct Entry_stack_elem));
    new_obj->value = _value;
    return new_obj;
}

void delete_Entry_stack_elem(Entry_stack_elem_t obj){
    free(obj);
}

Entry_stack_t new_Entry_stack(){
    Entry_stack_t new_obj = (Entry_stack_t)safe_malloc(sizeof(struct Entry_stack));
    new_obj->top = NULL;
    new_obj->size = 0;
    return new_obj;
}

void Entry_stack_push(Entry_stack_t stack, SymbolTableEntry_t val){
    Entry_stack_elem_t new_elem = new_Entry_stack_elem(val);
    new_elem->next = stack->top;
    stack->top = new_elem;
    stack->size++;
}

SymbolTableEntry_t Entry_stack_pop(Entry_stack_t stack){
    if(stack->size>0){
        stack->size--;
        Entry_stack_elem_t old_top = stack->top;
        SymbolTableEntry_t old_val = old_top->value;
        stack->top = stack->top->next;
        delete_Entry_stack_elem(old_top);
        return old_val;
    }
    ERROR("Attempting to pop empty stack!\n");
}


/**
 * Constructor for a SymbolTable object.
*/
SymbolTable_t new_SymbolTable()
{
    SymbolTable_t symtable = (SymbolTable_t)safe_malloc(sizeof(struct SymbolTable));
    symtable->num_buckets = SYMTABLE_NUM_BUCKETS;
    symtable->hashTable = (struct SymTable_Bucket*)safe_malloc(symtable->num_buckets*sizeof(struct SymTable_Bucket));

    //Initialization of buckets
    for (size_t index=0;index<symtable->num_buckets;index++)
    {
        symtable->hashTable[index].head = NULL;
        symtable->hashTable[index].length = 0;
    }

    return symtable;
}

SymbolTableEntry_t* new_SymbolTableVariable(char* name){
    SymbolTableEntry_t* new_entry = new_SymbolTableEntry(name, 0);
    return new_entry;
}

SymbolTableEntry_t* new_SymbolTableFormalVariable(char* name){
    SymbolTableEntry_t* new_entry = new_SymbolTableEntry(name, 1);
    return new_entry;
}

SymbolTableEntry_t* new_SymbolTableFunction(char* name){
    SymbolTableEntry_t* new_entry = new_SymbolTableEntry(name, 2);
    return new_entry;
}

SymbolTableEntry_t* new_SymbolTableLibFunction(char* name){
    SymbolTableEntry_t* new_entry = new_SymbolTableEntry(name, 3);
    return new_entry;
}

SymbolTableEntry_t* new_SymbolTableEntry(char* name, int function){
    ASSERT(name);
    
    SymbolTableEntry_t* new_entry = (SymbolTableEntry_t*)safe_malloc(sizeof(SymbolTableEntry_t));
    new_entry->isActive = true;
     if(function==1){
        new_entry->space = FORMALARG;
    }else if(scope_var==0){
        new_entry->space = PROGRAMVAR;
    }else{
        new_entry->space = FUNCTIONLOCAL;
    }

    if(function==2){
        new_entry->type = TYPE_USERFUNC;

        Function_t* new_func = (Function_t*)safe_malloc(sizeof(Function_t));
        new_func->name = strdup(name);
        new_func->line = yylineno;
        new_func->scope = scope_var;
        new_func->retlist = NULL;
        new_entry->value.funcVal = new_func;
    }else if(function==0 || function==1){

        if (function==1) {
            new_entry->type = TYPE_FORMAL;
        } else {
            if(scope_var==0){
                new_entry->type = TYPE_GLOBAL;
            }else{
                new_entry->type = TYPE_LOCAL;
            }
        }

        Variable_t* new_var = (Variable_t*)safe_malloc(sizeof(Variable_t));
        new_var->name = strdup(name);
        new_var->line = yylineno;
        new_var->scope = scope_var;
        new_entry->value.varVal = new_var;
    } else {
        new_entry->type = TYPE_LIBFUNC;
        Function_t* new_func = (Function_t*)safe_malloc(sizeof(Function_t));
        new_func->name = strdup(name);
        new_func->line = 0;
        new_func->scope = 0;
        new_func->retlist = NULL;
        new_entry->value.funcVal = new_func;
    }
    
    new_entry->isTable = false;

    return new_entry;
}
void SymbolTable_insert_local(SymbolTable_t symtable, SymbolTableEntry_t* entry, bool isAssignment)
{
    SymbolTable_insert_scoped(symtable, entry, true, isAssignment);
}

void SymbolTable_delete(SymbolTable_t symtable, char* key){

    int index = Universal_Hash(symtable->num_buckets,UNIVERSAL_HASH_P,key);

    ASSERT(index>=0);
    ASSERT(index<symtable->num_buckets);

    SymTable_Bucket_t* bucket = &symtable->hashTable[index];

    SymTable_Element_t* it = bucket->head;
    SymTable_Element_t* prev = NULL;

    while(it){
        SymbolTableEntry_t* entry = it->entry;
        int scope;
        char* name;
        if(isTypeVariable(entry->type)){
            scope = entry->value.varVal->scope;
            name = entry->value.varVal->name;
        }else{
            scope = entry->value.funcVal->scope;
            name = entry->value.funcVal->name;
        }

        if(scope==scope_var&&streq(name, key)){

            if(prev!=NULL){
                prev->next = it->next;
                free(it);
            }else{
                bucket->head = it->next;
                free(it);
            }

            return;
        }
        prev = it;
        it = it->next;
    }
}

void SymbolTable_insert_formal(SymbolTable_t symtable, SymbolTableEntry_t* entry)
{
    char* key;
    if (isTypeVariable(entry->type))
    {
        key = (char*)entry->value.varVal->name;
    }
    else
    {
        key = (char*)entry->value.funcVal->name;
    }

    int index = Universal_Hash(symtable->num_buckets,UNIVERSAL_HASH_P,key);

    ASSERT(index>=0);
    ASSERT(index<symtable->num_buckets);

    SymbolTableEntry_t* found_entry = symtable_bucket_lookup(&(symtable->hashTable[index]), key, scope_var, true, false,false);
    if(found_entry!=NULL){
        USER_ERROR("Formal variable '%s' redeclared in parameter list\n", key);
        return;
    }
    SymbolTable_insert_scoped(symtable, entry, true, true);
    increase_functionformalsoffset();
}

void SymbolTable_insert(SymbolTable_t symtable, SymbolTableEntry_t* entry, bool isAssignment)
{
    SymbolTable_insert_scoped(symtable, entry, false, isAssignment);
}

void SymbolTable_insert_scoped(SymbolTable_t symtable, SymbolTableEntry_t* entry, bool local, bool isAssignment)
{
    bool isFunction = false;

    ASSERT(symtable!=NULL);

    char* key;
    if (isTypeVariable(entry->type))
    {
        key = (char*)entry->value.varVal->name;
    }
    else
    {
        key = (char*)entry->value.funcVal->name;
        isFunction = true;
    }

    int index = Universal_Hash(symtable->num_buckets,UNIVERSAL_HASH_P,key);

    ASSERT(index>=0);
    ASSERT(index<symtable->num_buckets);

    SymbolTableEntry_t* old_element = symtable_bucket_lookup(&(symtable->hashTable[index]),
        key, -1, local, !isTypeVariable(entry->type),false); //Check if element already exists.

    if(old_element!=NULL){
        if(isAssignment&&(old_element->type==TYPE_USERFUNC||entry->type==TYPE_USERFUNC)&&getScope(old_element)==scope_var){
            USER_ERROR("Redefinition of symbol %s\n",key);
            //return;
        }
        else if(!(old_element->type==TYPE_USERFUNC||entry->type==TYPE_USERFUNC))
        {
            /*Shouldn't reinsert element*/
            return;
        }
        /*At this point, a function will be shadowed*/
    }

    if (isTypeVariable(entry->type))
    {
        if(entry->value.varVal->scope==0 || Funcstack_isempty(pfunc_jumpstack)){
            increase_globaloffset();
            printf("\nGLOBAL OFF: %d, name %s\n",get_global_vars(),(char*)entry->value.varVal->name);
            entry->value.varVal->offset = global_offset;

        }else{
            increase_functionlocalsoffset();
            entry->value.varVal->offset = functionlocalsoffset;
        }
    }
    else
    {
       if(entry->value.funcVal->scope==0 || Funcstack_isempty(pfunc_jumpstack)){
            //printf("funcstack is %d\n", pfunc_jumpstack->size);
            increase_globaloffset();
            entry->value.funcVal->offset = global_offset;

        }else{
            increase_functionlocalsoffset();
            entry->value.funcVal->offset = functionlocalsoffset;
        }
    }
    symtable_bucket_insert(&(symtable->hashTable[index]),entry);
}

/**
 * Performs a lookup on the symbol table, based on the given search key.
 * 
 * @param bucket The symbol table to search.
 * @param key The search key.
 * 
 * @return The element if it exists, NULL otherwise.
*/
SymbolTableEntry_t* SymbolTable_lookup(SymbolTable_t symtable, char* key, bool isTemp)
{
    ASSERT(symtable!=NULL);

    int index = Universal_Hash(symtable->num_buckets,UNIVERSAL_HASH_P,key);
    ASSERT(index>=0);
    ASSERT(index<symtable->num_buckets);

    return symtable_bucket_lookup(&(symtable->hashTable[index]),key, -1, false, false,isTemp);
}

/**
 * Performs a lookup on the symbol table, based on the given search key, but don't fail if not found, just return NULL.
 * 
 * @param bucket The symbol table to search.
 * @param key The search key.
 * 
 * @return The element if it exists, NULL otherwise.
*/
SymbolTableEntry_t* SymbolTable_lookup_chill(SymbolTable_t symtable, char* key)
{
    ASSERT(symtable!=NULL);
    int index = Universal_Hash(symtable->num_buckets,UNIVERSAL_HASH_P,key);

    ASSERT(index>=0);
    ASSERT(index<symtable->num_buckets);

    SymbolTableEntry_t* entry = symtable_bucket_lookup(&(symtable->hashTable[index]),key, -1, false, true, false);
    
    // if(entry!=NULL&&entry->value.varVal!=NULL)printf("[chill lookup returned entry with key %s and offset %d]\n", key, entry->value.varVal->offset);
    return entry;
}

/**
 * Performs a lookup on the symbol table, based on the given search key.
 * 
 * @param bucket The symbol table to search.
 * @param key The search key.
 * 
 * @return The element if it exists, NULL otherwise.
*/
SymbolTableEntry_t* SymbolTable_lookup_global(SymbolTable_t symtable, char* key)
{
    ASSERT(symtable!=NULL);

    int index = Universal_Hash(symtable->num_buckets,UNIVERSAL_HASH_P,key);
    ASSERT(index>=0);
    ASSERT(index<symtable->num_buckets);

    return symtable_bucket_lookup(&(symtable->hashTable[index]),key, 0, false, false, false);
}

/**
 * Checks if the given key corresponds to a reachable variable, 
 * invokes an error if not.
 * 
 * @param bucket The symbol table to search.
 * @param key The search key.
 * 
*/
void SymbolTable_require(SymbolTable_t symtable, char* key)
{
    ASSERT(symtable!=NULL);

    int index = Universal_Hash(symtable->num_buckets,UNIVERSAL_HASH_P,key);

    ASSERT(index>=0);
    ASSERT(index<symtable->num_buckets);

    if(symtable_bucket_lookup(&(symtable->hashTable[index]),key, -1, false, false,false)==NULL){
        USER_ERROR("Referencing non-existent '%s'\n",key);
    }
}

/**
 * Checks if the given key corresponds to a global variable, 
 * invokes an error if not.
 * 
 * @param bucket The symbol table to search.
 * @param key The search key.
 * 
*/
void SymbolTable_require_global(SymbolTable_t symtable, char* key)
{
    ASSERT(symtable!=NULL);

    int index = Universal_Hash(symtable->num_buckets,UNIVERSAL_HASH_P,key);

    ASSERT(index>=0);
    ASSERT(index<symtable->num_buckets);

    if(symtable_bucket_lookup(&(symtable->hashTable[index]),key, 0, false, false,false)==NULL){
        USER_ERROR("Referencing non-existent global '%s'\n",key);
    }
}

void Symtable_invalidate_scope(SymbolTable_t symtable)
{
    for(size_t i=0;i<symtable->num_buckets;i++){
        SymTable_Element_t* bucket_it = symtable->hashTable[i].head;

        while(bucket_it!=NULL){
            SymbolTableEntry_t* current_entry = bucket_it->entry;

            unsigned int entry_scope;
            if (isTypeVariable(current_entry->type))
            {
                entry_scope = current_entry->value.varVal->scope;
            }else{
                entry_scope = current_entry->value.funcVal->scope;
            }

            if(scope_var==entry_scope)
            {
                current_entry->isActive = false;
            }
            bucket_it = bucket_it->next;
        }
    }
}

void symtable_bucket_insert(SymTable_Bucket_t* bucket, SymbolTableEntry_t* entry)
{
    ASSERT(bucket!=NULL);
    ASSERT(entry!=NULL);

    SymTable_Element_t* new_element = (SymTable_Element_t*)safe_malloc(sizeof(SymTable_Element_t));
    new_element->entry = entry;
    new_element->next = NULL;

    if (bucket->head==NULL){
        bucket->head = new_element;
        
    }else{
        new_element->next = bucket->head;
        bucket->head = new_element;
    }

    bucket->length++;
}

/**
 * Performs a lookup on a bucket, based on the given search key.
 * 
 * @param bucket The bucket to search.
 * @param key The search key.
 * @param scope The search scope, -1 for no scope limit.
 * @param local Whether the parameter should only be looked for in the current scope or not.
 * @param isTemp to konw if I am going to search for a temp variable 
 * @return The element if it exists, NULL otherwise.
*/
SymbolTableEntry_t* symtable_bucket_lookup(SymTable_Bucket_t* bucket, char* key, long int scope, bool local, bool allow_shadowing,bool isTemp)
{
    ASSERT(bucket!=NULL);
    ASSERT(key!=NULL);

    bool invalid_scope = false;

    unsigned int min_scope;
    unsigned int starting_scope = scope_var;

    if(local){
        min_scope = scope_var;
    }else{
        min_scope = 0;
    }

    for(unsigned int lookup_scope = starting_scope+1;lookup_scope>min_scope;lookup_scope--){
        SymTable_Element_t* current_element = bucket->head;
    
      
        while(current_element!=NULL)
        {
           
            const char* found_key;
            unsigned int entry_scope;
            if (isTypeVariable(current_element->entry->type))
            {
                found_key = current_element->entry->value.varVal->name;
                entry_scope = current_element->entry->value.varVal->scope;
            }
            else
            {
                found_key = current_element->entry->value.funcVal->name;
                entry_scope = current_element->entry->value.funcVal->scope;
            }

            if(streq(key,found_key) && isTemp==true && !current_element->entry->isActive)
            { 
                 return (current_element->entry);
            }else if (streq(key,found_key)&&entry_scope==lookup_scope-1&&current_element->entry->isActive)
            { 
               
                if(!isTemp&&!allow_shadowing&&invalid_scope&&lookup_scope>1&&current_element->entry->type!=TYPE_USERFUNC){
                    USER_ERROR("Variable '%s' unreachable from within referenced scope!\n",key);
                }
                //Key found, return entry
                return (current_element->entry);
            }
            current_element = current_element->next;
        }
        
        
        

        if(scope_var>0&&check_scope_offset()){
            invalid_scope = true;
            continue;
        }
    }

    return NULL;
}

void printSymbolTableContents(SymbolTable_t symtable){
    Entry_stack_t* scopeStacks = (Entry_stack_t*)safe_malloc((max_scope+1)*sizeof(Entry_stack_t));
    memset(scopeStacks,0,(max_scope+1)*sizeof(Stack_t));

    for(size_t i=0;i<symtable->num_buckets;i++){
        SymTable_Element_t* bucket_it = symtable->hashTable[i].head;

        while(bucket_it!=NULL){
            SymbolTableEntry_t* current_entry = bucket_it->entry;

            unsigned int var_lineno;
            unsigned int var_scope;
            char* var_name;

            if (isTypeVariable(current_entry->type))
            {
                var_name = (char*)current_entry->value.varVal->name;
                var_lineno = current_entry->value.varVal->line;
                var_scope = current_entry->value.varVal->scope;
            }
            else
            {
                var_name = (char*)current_entry->value.funcVal->name;
                var_lineno = current_entry->value.funcVal->line;
                var_scope = current_entry->value.funcVal->scope;
            }

            if(scopeStacks[var_scope]==NULL){
                scopeStacks[var_scope] = new_Entry_stack();
            }

            Entry_stack_push(scopeStacks[var_scope],*current_entry);
            bucket_it = bucket_it->next;
        }
    }

    for (size_t i=0;i<max_scope+1;i++){
        SymbolTableEntry_t current_entry;
        size_t stack_index = 0;

        if (scopeStacks[i]==NULL)continue;

        fprintf(stdout, "----------------------------------Scope %lu----------------------------------\n", i);

        while(stack_index<scopeStacks[i]->size){

            current_entry = Entry_stack_lookup(scopeStacks[i],stack_index);

            unsigned int var_lineno;
            unsigned int var_scope;
            char* var_name;

            if (isTypeVariable(current_entry.type))
                {
                    var_name = (char*)current_entry.value.varVal->name;
                    var_lineno = current_entry.value.varVal->line;
                    var_scope = current_entry.value.varVal->scope;
                }
                else
                {
                    var_name = (char*)current_entry.value.funcVal->name;
                    var_lineno = current_entry.value.funcVal->line;
                    var_scope = current_entry.value.funcVal->scope;
                }

                fprintf(stdout, "%s  \t [%s] \t (line %u) \t (scope %u)\n",var_name,typeToString(current_entry.type) ,var_lineno, var_scope);

                stack_index++;
            }
    }
}

char* typeToString(enum SymbolType type) {
    switch(type) {
        case TYPE_FORMAL:
            return "TYPE_FORMAL";
            break;
        case TYPE_GLOBAL:
            return "TYPE_GLOBAL";
            break;
        case TYPE_LIBFUNC:
            return "TYPE_LIBFUNC";
            break;
        case TYPE_USERFUNC:
            return "TYPE_USERFUNC";
            break;
        case TYPE_LOCAL:
            return "TYPE_LOCAL";
            break;
        default:
            break;
    }
}

char* library_function_names[]={
    "print","input","objectmemberkeys",
    "objecttotalmembers","objectcopy","totalarguments",
    "argument","typeof","strtonum","sqrt","cos","sin"
};

struct Expr_Type{
    enum{EXPR_TYPE_INT,EXPR_TYPE_REAL,EXPR_TYPE_STR} type;
    union{
        int intVal;
        double realVal;
        char* stringVal;
    }value;
};

void assign_expr_from(Expr_Type_t* expr_to, Expr_Type_t* expr_from)
{
    ASSERT(expr_to!=NULL);
    ASSERT(expr_from!=NULL);

    switch (expr_from->type)
    {
    case EXPR_TYPE_INT:
        assign_expr_int(*expr_to,expr_from->value.intVal);
        break;
    case EXPR_TYPE_REAL:
        assign_expr_real(*expr_to,expr_from->value.realVal);
        break;
    case EXPR_TYPE_STR:
        assign_expr_str(*expr_to,expr_from->value.stringVal);
        break;
    default:
        ERROR("Invalid expression type!\n");
    }
}

bool expr_to_bool(Expr_Type_t expr)
{
    switch (expr.type)
    {
    case EXPR_TYPE_INT:
        return (expr.value.intVal!=0);
    case EXPR_TYPE_REAL:
        return (expr.value.realVal!=0);
    case EXPR_TYPE_STR:
        return (strcmp(expr.value.stringVal,""));
    default:
        ERROR("Invalid expression type!\n");
        break;
    }
}

bool expr_bool_inverse(Expr_Type_t* expr)
{
    switch (expr->type)
    {
    case EXPR_TYPE_INT:
        if(expr->value.intVal){
            return false;
        }
        else{
            return true;
        }
        break;
    case EXPR_TYPE_REAL:
        if(expr->value.realVal){
            return false;
        }
        else{
            return true;
        }
        break;
    case EXPR_TYPE_STR:
        LOG("WARNING","Attempting to invert string value\n");
        return false;
    default:
        ERROR("Invalid expression type!\n");
    }
}

double get_expr_as_num(Expr_Type_t expr)
{
    ASSERT(expr.type!=EXPR_TYPE_STR);

    if (expr.type==EXPR_TYPE_INT)
    {
        return (double)expr.value.intVal;
    }

    return expr.value.realVal;
}

enum comparator{COMPARE_EQUAL, COMPARE_GREATER_THAN, COMPARE_LESS_THAN, COMPARE_GREATER_EQUAL, COMPARE_LESS_EQUAL, COMPARE_NOT_EQUAL, COMPARE_AND, COMPARE_OR};

int compare_expr(Expr_Type_t* expr1, Expr_Type_t* expr2, enum comparator how)
{
    bool types_match = (expr1->type==expr2->type)||
        ((expr1->type==EXPR_TYPE_INT||expr1->type==EXPR_TYPE_REAL)&&(expr2->type==EXPR_TYPE_INT||expr2->type==EXPR_TYPE_REAL));

    if (!types_match){
        LOG("WARNING","Comparing incompatible types!\n");
        return false;
    }

    double op1,op2;

    switch (how)
    {
    case COMPARE_EQUAL:
        if(expr1->type==EXPR_TYPE_STR)
        {
            return streq(expr1->value.stringVal,expr2->value.stringVal);
        }
        op1 = get_expr_as_num(*expr1);
        op2 = get_expr_as_num(*expr2);
        return op1==op2;

    case COMPARE_NOT_EQUAL:
        if(expr1->type==EXPR_TYPE_STR)
        {
            return !streq(expr1->value.stringVal,expr2->value.stringVal);
        }
        op1 = get_expr_as_num(*expr1);
        op2 = get_expr_as_num(*expr2);
        return op1!=op2;

    case COMPARE_GREATER_THAN:
        if(expr1->type==EXPR_TYPE_STR)
        {
            LOG("WARNING","Attempting to use > operator on strings!\n");
            return false;
        }
        op1 = get_expr_as_num(*expr1);
        op2 = get_expr_as_num(*expr2);
        return op1>op2;
    
    case COMPARE_LESS_THAN:
        if(expr1->type==EXPR_TYPE_STR)
        {
            LOG("WARNING","Attempting to use < operator on strings!\n");
            return false;
        }
        op1 = get_expr_as_num(*expr1);
        op2 = get_expr_as_num(*expr2);
        return op1<op2;

    case COMPARE_GREATER_EQUAL:
        if(expr1->type==EXPR_TYPE_STR)
        {
            LOG("WARNING","Attempting to use >= operator on strings!\n");
            return false;
        }
        op1 = get_expr_as_num(*expr1);
        op2 = get_expr_as_num(*expr2);
        return op1>=op2;

    case COMPARE_LESS_EQUAL:
        if(expr1->type==EXPR_TYPE_STR)
        {
            LOG("WARNING","Attempting to use <= operator on strings!\n");
            return false;
        }
        op1 = get_expr_as_num(*expr1);
        op2 = get_expr_as_num(*expr2);
        return op1<=op2;
    
    case COMPARE_AND:
        if(expr1->type==EXPR_TYPE_STR)
        {
            LOG("WARNING","Attempting to use 'and' operator on strings!\n");
            return false;
        }
        return expr_to_bool(*expr1)&&expr_to_bool(*expr2);

    case COMPARE_OR:
        if(expr1->type==EXPR_TYPE_STR)
        {
            LOG("WARNING","Attempting to use 'or' operator on strings!\n");
            return false;
        }
        return expr_to_bool(*expr1)||expr_to_bool(*expr2);

    default:
        ASSERT(false);
    }
}

enum SymbolType getScope(SymbolTableEntry_t* entry){
    if(isTypeVariable(entry->type)){
        return entry->value.varVal->scope;
    }
    return entry->value.funcVal->scope;
}

enum iopcode
{
	assign_i,
	add_i,
	sub_i,
	mul_i,
	div_i,
	mod_i,
    uminus_i,
    // and_i,
    // or_i,
    // not_i,
	jump_i,
	if_eq_i,
	if_noteq_i,
	if_lesseq_i,
	if_greatereq_i,
	if_less_i,
	if_greater_i,
	call_i,
	param_i,
	funcstart_i,
	funcend_i,
	tablecreate_i,
	tablegetelem_i,
	tablesetelem_i,
	getretval_i,
	ret_i
};

char* opcodeToString[] = {
    "ASSIGN",         "ADD",            "SUB",
    "MUL",            "DIV",            "MOD",
    "UMINUS",        
    "JUMP",           "IF_EQ",          "IF_NOTEQ",
    "IF_LESSEQ",      "IF_GREATEREQ",   "IF_LESS",
    "IF_GREATER",     "CALL",           "PARAM",
    "FUNCSTART",      "FUNCEND",        "TABLECREATE",    
    "TABLEGETELEM",   "TABLESETELEM",   "GETRETVAL",
    "RET"
};

char* targetToString[] = {
    "assign",         "add",            "sub",
    "mul",            "div",            "mod",        
    "jump",           "jeq",            "jne",
    "jle",            "jge",            "jlt",
    "jgt",            "call",           "pusharg",
    "funcenter",      "funcexit",       "newtable",    
    "tablegetelem",   "tablesetelem",    "nop"
};

enum expr_t
{

	var_e,
	tableitem_e,

	programfunc_e,
    callfunc_e,
	libraryfunc_e,
    for_e,
    return_e,
    loop_e,

	arithexpr_e,
	boolexpr_e,
	assignexpr_e,
	newtable_e,

	constnum_e,
	constbool_e,
	conststring_e,

	nil_e
};

struct expr
{
	expr_t type;
	SymbolTableEntry_t* sym;
	expr *index;
	double numConst;
	char *strConst;
	int boolConst;
    int method;
    int totalLocals;
    quad* lastAssignedQuad;
	expr *next;
    expr *prev;
    int true_list;
    int false_list;
    int break_list;
    int cont_list;
    int test;
    int enter;
};

struct quad
{
	iopcode op;
	expr *result;
	expr *arg1;
	expr *arg2;
	unsigned int label;
	unsigned int line;
    unsigned int src_line;
    unsigned int taddress;
};

void Check_type(expr* x) {
    if (x->type == boolexpr_e || x->type == constbool_e || x->type == conststring_e || x->type == nil_e || x->type == programfunc_e || x->type == libraryfunc_e) {
        USER_ERROR("Incompatible types!\n");
    }
    return;
}

void expand(){
    ASSERT(total_quads==curr_quad);

    quads = (quad*)realloc(quads, NEW_SIZE);

    if(quads==NULL){
        fprintf(stderr, "Error, unable to allocate memory\n");
        exit(EXIT_FAILURE);
    }

    total_quads += EXPAND_SIZE;
}

void emit(
    iopcode op,
    expr* arg1,
    expr* arg2,
    expr* result,
    unsigned int label
){
    if(curr_quad==total_quads)
        expand();

    quad* q = quads+curr_quad++;
    q->op = op;
    q->arg1 = arg1;
    q->arg2 = arg2;
    q->result = result;
    if(q->result!=NULL)
        
        q->result->lastAssignedQuad = q;

    q->label = label;
    q->line = curr_quad-1;
    q->src_line = yylineno;
}

unsigned int nextQuadLabel(){
    return curr_quad;
}

expr* emitIfTableItem(expr* e){
    if(e->type!=tableitem_e){
        return e;
    }else{
        expr* result = new_Expr(var_e);
        result->sym = newTemp();
        result->strConst = result->sym->value.varVal->name;
        emit(tablegetelem_i, e, e->index, result, 0);
        return result;
    }
}

void printQuads(FILE* file){
    fprintf(file, "\n\n\n\n");
    for(unsigned index=1;index<curr_quad;index++){
        quad* q = quads+index;
        fprintf(file, "\033[0;33mSource line: %3d, Line %3d: %s", q->src_line, q->line, opcodeToString[q->op]);
        
        //if(q->arg1!=NULL)printf("arg 1 is %s\n", expr_to_string(q->arg1));
        if(q->arg1!=NULL)fprintf(file, " %s", expr_to_string(q->arg1)); //printf("\n");
        //if(q->arg2!=NULL)printf("arg 2 is %s\n", expr_to_string(q->arg2));
        if(q->arg2!=NULL)fprintf(file, " %s", expr_to_string(q->arg2)); //printf("\n");
        //if(q->result!=NULL)printf("result is %s\n", expr_to_string(q->result));
        if(q->result!=NULL)fprintf(file, " %s", expr_to_string(q->result)); //printf("\n");
      
        if (q->op == jump_i && q->label == 0) {
            fprintf(file, " %d", q->label);
        } else if (q->label != 0){
            fprintf(file, " %d", q->label);
        }
        fprintf(file, "\033[0m\n");
    }
}


char* expr_to_string(expr* e){
    assert(e);
    double counter_len;
    char* num_str;
    switch (e->type)
    {
    case nil_e:
        return "NIL";
    case var_e:
        return e->strConst;
    case constnum_e:
            return num_to_str(e->numConst);
    case constbool_e:
            if(e->boolConst){
                return "TRUE";
            }
            return "FALSE";
    case conststring_e:
        return e->strConst;
    case arithexpr_e:
        if(isTypeVariable(e->type)){
            return e->sym->value.varVal->name;
        }
        return e->sym->value.funcVal->name;
    case boolexpr_e:
        //if (e->strConst == NULL) printf("strconst null"); 
        if (e->sym == NULL) {return e->strConst;} 
        if(isTypeVariable(e->sym->type)){
            return e->sym->value.varVal->name;
        }
        return e->sym->value.funcVal->name;
    case assignexpr_e:

        if(isTypeVariable(e->type)){
            return e->sym->value.varVal->name;
        }
        return e->sym->value.funcVal->name;
    case libraryfunc_e:
    case programfunc_e:
        if (e->sym == NULL) return e->strConst; 
        return e->sym->value.funcVal->name;
    case callfunc_e:
        if (e->sym == NULL) return e->strConst;
        return e->sym->value.funcVal->name;
    case return_e:
        if(e==NULL){
            return "";
        }
        if(e->sym!=NULL){
            return e->sym->value.varVal->name;
        }else if(e->strConst==NULL){
            if(e->boolConst==INVALID_BOOL){
                return num_to_str(e->numConst);
            }else{
                return (e->boolConst?"TRUE":"FALSE");
            }
        }

        return e->strConst;
    case tableitem_e:
        if(e->sym!=NULL){
            if(isTypeVariable(e->sym->type)){
                return e->sym->value.varVal->name;
            }
            return e->sym->value.funcVal->name;
        }else if(e->strConst==NULL){
            if(e->boolConst==INVALID_BOOL){
                return num_to_str(e->numConst);
            }else{
                return (e->boolConst?"TRUE":"FALSE");
            }
        }
        return e->strConst;
    case newtable_e:
        if(e->strConst==NULL){
            return e->sym->value.varVal->name;
        }
        return e->strConst;
    default:
        return NULL;
    }

}

// SymbolTableEntry_t* newTemp(){
//     double counter_len;
//     char* name;
//     SymbolTableEntry_t* entry;
    
//     counter_len = log10((double)inner_counter_for_temp)+1;
//     name = safe_malloc((int)counter_len*sizeof(char*));
//     sprintf(name, "_t%d", inner_counter_for_temp);
//     entry = SymbolTable_lookup_local(symbol_table, name);
//     if(entry==NULL){
//         entry = new_SymbolTableEntry(name, false);
//         // entry->value.varVal->scope = 0;
//         // entry->space = PROGRAMVAR;
//         // entry->type = TYPE_GLOBAL;
//         SymbolTable_insert_temp(symbol_table,entry);
        
//     }
//     inner_counter_for_temp++;
//     return entry;
// }

SymbolTableEntry_t* newTemp() {

    double counter_len;
    char* name;
    SymbolTableEntry_t* entry;

    if((total_new_temps_used_in_stmt==0) || (inner_counter_for_temp-1==total_new_temps_used_in_stmt)){


        counter_len = log10((double)inner_counter_for_temp)+1;

        name = safe_malloc((int)counter_len*sizeof(char*));

        sprintf(name, "_t%d", inner_counter_for_temp);

        entry = new_SymbolTableEntry(name, false);
        SymbolTable_insert_local(symbol_table,entry,false);
        
        inner_counter_for_temp++;
        if(inner_counter_for_temp>total_new_temps_used_in_stmt){ //update max temps used in 1 stmt
            total_new_temps_used_in_stmt=inner_counter_for_temp-1;
            remain_available_temps=total_new_temps_used_in_stmt;
        }
       

    }else{
        int temp_rank;
        temp_rank=remain_available_temps;
        remain_available_temps--;
        counter_len = log10((double)(temp_rank))+1;

        name = safe_malloc((int)counter_len*sizeof(char*));

        sprintf(name, "_t%d", temp_rank);
      
        entry = SymbolTable_lookup_local(symbol_table,name);
        if(entry==NULL){
            entry = new_SymbolTableEntry(name, false);
            // entry->value.varVal->scope = 0;
            // entry->space = PROGRAMVAR;
            // entry->type = TYPE_GLOBAL;
            SymbolTable_insert_temp(symbol_table,entry);
        }
        inner_counter_for_temp++;
    }
    return entry;

}

void SymbolTable_insert_temp(SymbolTable_t symtable, SymbolTableEntry_t* entry)
{
    ASSERT(symtable!=NULL);

    char* key;
    if (isTypeVariable(entry->type))
    {
        key = (char*)entry->value.varVal->name;
    }
    else
    {
        key = (char*)entry->value.funcVal->name;
    }

    int index = Universal_Hash(symtable->num_buckets,UNIVERSAL_HASH_P,key);

    ASSERT(index>=0);
    ASSERT(index<symtable->num_buckets);

    SymbolTableEntry_t* old_element = symtable_bucket_lookup(&(symtable->hashTable[index]),
        key, 0, true, false,false); //Check if element already exists.

    if(old_element!=NULL){
       // return;
        ERROR("Redefinition of temp %s\n",key);
    }

    if(scope_var==0||Funcstack_isempty(pfunc_jumpstack)){
        increase_globaloffset();
        entry->value.varVal->offset = global_offset;
    }else{
        increase_functionlocalsoffset();
        entry->value.varVal->offset = functionlocalsoffset;
    }
     symtable_bucket_insert(&(symtable->hashTable[index]),entry);
}



SymbolTableEntry_t* SymbolTable_lookup_local(SymbolTable_t symtable, char* key)
{
    ASSERT(symtable!=NULL);

    int index = Universal_Hash(symtable->num_buckets,UNIVERSAL_HASH_P,key);
    ASSERT(index>=0);
    ASSERT(index<symtable->num_buckets);

    return symtable_bucket_lookup(&(symtable->hashTable[index]),key, -1, true, false,false);
}

void reset_counter_temp(){
    inner_counter_for_temp=1;
    remain_available_temps=total_new_temps_used_in_stmt;
}


expr* new_Expr(expr_t type){
    expr* new_expr = (expr*)safe_malloc(sizeof(expr));
    new_expr->type = type;
    new_expr->next = NULL;
    new_expr->numConst = 0;
    new_expr->boolConst = -1;
    new_expr->method = false;
    new_expr->strConst = NULL;
    new_expr->next = NULL;
    new_expr->prev = NULL;
    new_expr->sym = NULL;
    new_expr->index = NULL;
    new_expr->true_list = 0;
    new_expr->false_list = 0;
    new_expr->break_list = 0;
    new_expr->cont_list = 0;
    new_expr->lastAssignedQuad = NULL;
    return new_expr;
}

expr* new_var(char* id){
    expr* e = new_Expr(var_e);
    e->strConst = strdup(id);
    return e;
}

expr* new_conststring(char* str){
    expr* e = new_Expr(conststring_e);
    e->strConst = strdup(str);
    return e;
}

expr* new_constnum(double n){
    expr* e = new_Expr(constnum_e);
    e->numConst = n;
    return e;
}

expr* new_constbool(bool cond){
    expr* e = new_Expr(constbool_e);
    e->boolConst = cond;
    return e;
}

expr* new_call(char* name){
    expr* e = new_Expr(callfunc_e);
    e->strConst = name;
    return e;
}

expr* member_item(expr* lv, char* name){
    expr* old_lv = lv;
    lv = emitIfTableItem(lv);

    expr* ti;
    if(lv!=old_lv){
        ti = new_Expr(var_e);
    }else{
        ti = new_Expr(tableitem_e);
    }
    ti->sym = lv->sym;
    ti->lastAssignedQuad = lv->lastAssignedQuad;
    if(ti->sym==NULL){
        ti->strConst = lv->strConst;
    }else{
        ti->strConst = ti->sym->value.varVal->name;
    }
    
    ti->index = new_conststring(name);
    return ti;
}

expr* make_call(expr* lv, expr* reversed_elist){
    //expr* func = emit_iftableitem(lv);
    while (reversed_elist) {
        emit(param_i, reversed_elist, NULL, NULL, 0);
        reversed_elist = reversed_elist->next;
    }
    
    if (!lv->sym->isTable) {
        lv->type = callfunc_e;
    }
    
    emit(call_i, lv,NULL, NULL, 0); //lv should be func
    expr* result = new_Expr(callfunc_e);
    result->sym = newTemp();
    result->strConst = result->sym->value.varVal->name;
    emit(getretval_i, NULL, NULL, result, 0);
    result->type = var_e;
    return result;
}

/**
 * This function is meant to be called inside the member assign expression,
 * in order to get rid of the last unnecessary 'tablegetelem' quad placed by 'member'
 * and replace it with the proper 'tablesetelem' quad.
*/
expr* fixAssignedMember(expr* member, expr* assigned_val){
    assert(member->lastAssignedQuad!=NULL);

    quad lastQuad = *(member->lastAssignedQuad);

    /*
        Shift all quads after the 'get' quad by -1 position, to overwrite the
        reduntant quad and place the new one at the end.
    */
    quad* q;
    for(q = member->lastAssignedQuad; q-quads<curr_quad-1; q++){
        *q = *(q+1);
        q->line = q->line-1; //Update line accordingly
        if(q->label){
            q->label--;
        }
    }

    lastQuad.result = assigned_val;
    lastQuad.op = tablesetelem_i;
    lastQuad.result->lastAssignedQuad = q;
    lastQuad.line = q->line; //Update line accordingly

    *q = lastQuad;

    return q->result;
}

char* addStringLiterals(char* str){
    ASSERT(str);
    int str_len = strlen(str);
    char* new_string = malloc((str_len+4)*sizeof(char));
    sprintf(new_string, "\"%s\"", str);
    free(str);
    return new_string;
}

/**
 * Sets the value that points to the quad associated with the
 * expression. To be used in member access.
*/
void assignParentTable(expr* e){
    e->lastAssignedQuad = quads+(curr_quad-1);
}

void printArgs(expr* list){
    int i=0;
    while(list){
        if(list->strConst==NULL){
            if(list->boolConst==INVALID_BOOL){
                printf("arg #%d: %f\n",i,list->numConst);
            }else{
                printf("arg #%d: %s\n",i,(list->boolConst)?"TRUE":"FALSE");
            }
        }else{
            printf("arg #%d: %s\n",i,list->strConst);
        }
        list = list->next;
        i++;
    }
}

//Quad list//
// struct Quad_list_node {
//     int value;
//     Quad_list_node_t next;
// };

// struct Quad_list {
//     Quad_list_node_t head;
//     Quad_list_node_t tail;
//     size_t len;
// };

// struct stmt_t {
//     int break_list, cont_list;
// };

void make_stmt (expr* e) { 
    
    e->break_list = e->cont_list = 0; 

}

int newlist (int i) { 

    quads[i].label = 0;
    return i;
    
}

int mergelist (int l1, int l2) {
    if (!l1)
        return l2;
    else
        if (!l2)
            return l1;
        else {
            int i = l1;
            while (quads[i].label){
                i = quads[i].label;
            }
            quads[i].label = l2;
            return l1;
    }
}

void patchLabel(unsigned quadNo, unsigned label){
    ASSERT(quadNo < curr_quad && quadNo>=0 && !quads[quadNo].label);
    quads[quadNo].label = label;
}

void patchlist (int list, int label) {
    while (list) {
        int next = quads[list].label;
        quads[list].label = label;
        list = next;
    }
}

void printlist (int list) {
    int i = 0;
    while (list) {
        printf("list[%d] = %d\n", i, list);
        int next = quads[list].label;
        list = next;
        i++;
    }
}

void patchANDOp1(expr* e){
    if(e->type != boolexpr_e){
        emit(if_eq_i, new_constbool(true), e, NULL, nextQuadLabel());
        emit(jump_i, NULL, NULL, NULL, nextQuadLabel());
        e->true_list = newlist(nextQuadLabel()-2);
        e->false_list = newlist(nextQuadLabel()-1);

        patchlist(e->true_list, nextQuadLabel());
    }
}

void patchOROp1(expr* e){
    if(e->type != boolexpr_e){
        emit(if_eq_i, new_constbool(true), e, NULL, nextQuadLabel());
        emit(jump_i, NULL, NULL, NULL, nextQuadLabel());
        e->true_list = newlist(nextQuadLabel()-2);
        e->false_list = newlist(nextQuadLabel()-1);

        patchlist(e->false_list, nextQuadLabel());
    }
}

void patchEQNEQOp1(expr* e){
    if(e->type == boolexpr_e){
        e->sym = newTemp();
        patchlist(e->true_list, nextQuadLabel());
        emit(assign_i, new_constbool(true), NULL, e, 0);
        emit(jump_i, NULL, NULL, NULL, nextQuadLabel()+2);
        patchlist(e->false_list, nextQuadLabel());
        emit(assign_i, new_constbool(false), NULL, e, 0);
    }
}

expr* moveToEnd(expr* e){
    if (e==NULL) return NULL;
    for(;e->next;e = e->next);

    return e;
}

void increase_globaloffset(){
    global_offset++;
}

void increase_functionformalsoffset(){
    functionformalsoffset++;
}

void  increase_functionlocalsoffset(){
    functionlocalsoffset++;
}

bool isConstExpr(expr* e){
    return(
        e->type==nil_e||
        e->type==constnum_e||
        e->type==conststring_e||
        e->type==constbool_e||
        e->type==boolexpr_e||
        e->type==arithexpr_e||
        e->type==boolexpr_e||
        e->type==assignexpr_e
    );
}

bool isOfSameScope(SymbolTableEntry_t* entry){
    if(isTypeVariable(entry->type)){
        return entry->value.varVal->scope == scope_var;
    }
    return entry->value.funcVal->scope == scope_var;
}

#endif
