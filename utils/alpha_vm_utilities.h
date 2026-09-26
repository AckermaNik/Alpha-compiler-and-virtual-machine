/**
 * @file alpha_vm_utilities.h
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

#ifndef ALPHA_VM_UTILITIES_H
#define ALPHA_VM_UTILITIES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alpha_general_types.h"
#include "alpha_definitions.h"
#include "alpha_general_utilities.h"


typedef struct avm_table avm_table;
typedef struct avm_memcell avm_memcell;
typedef enum avm_memcell_t avm_memcell_t;
typedef void (*memclear_func_t)(avm_memcell* m);
typedef void (*library_func_t)(void);
typedef void(*execute_func_t)(instruction* instr);
typedef double(*arithmetic_func_t)(double x, double y);
typedef char*(*tostring_func_t)(avm_memcell* m);
typedef bool(*jump_func_t)(double x, double y);
typedef unsigned char(*tobool_func_t)(avm_memcell* m);
typedef struct avm_table_bucket avm_table_bucket;

//
extern avm_memcell ax, bx, cx;
extern avm_memcell retval;
extern unsigned top, topsp;

extern unsigned            pc;
extern unsigned            currLine;
extern unsigned            codeSize;
extern unsigned char       executionFinished;
extern instruction*        code;
extern unsigned            totalGlobals;
//

void execute_add(instruction *instr);
void execute_sub(instruction *instr);
void execute_mul(instruction *instr);
void execute_div(instruction *instr);
void execute_mod(instruction *instr);
void execute_assign(instruction *instr);
void execute_call(instruction *instr);
void execute_pusharg(instruction *instr);
void execute_funcenter(instruction *instr);
void execute_funcexit(instruction *instr);
void execute_jeq(instruction *instr);
void execute_jne(instruction *instr);
void execute_jle(instruction *instr);
void execute_jge(instruction *instr);
void execute_jlt(instruction *instr);
void execute_jgt(instruction *instr);
void execute_newtable(instruction *instr);
void execute_tablegetelem(instruction *instr);
void execute_tablesetelem(instruction *instr);
void execute_nop(instruction *instr);
void execute_jump(instruction *instr);
//
void execute_cycle(void);
void loadBinaryFile(FILE* file);
void avm_initstack();
void memclear_string(avm_memcell* m);
void memclear_table(avm_memcell* m);

char* removeStringLiterals(char* str);
//
extern unsigned char executionFinished;

extern memclear_func_t memclearFuncs[];
extern execute_func_t executeFuncs[];
extern library_func_t lib_funcs[];
//
enum avm_memcell_t{
    number_m,
    string_m,
    bool_m,
    table_m,
    userfunc_m,
    libfunc_m,
    nil_m,
    undef_m
};

struct avm_memcell{
    union{
        double          numVal;
        char*           strVal;
        unsigned char   boolVal;
        avm_table*      tableVal;
        unsigned        funcVal;
        char*           libfuncVal;
    }data;
    avm_memcell_t type;
    char* info;
};



extern avm_memcell stack[AVM_STACKSIZE];


struct avm_table_bucket {
    avm_memcell key;
    avm_memcell value;
    avm_table_bucket* next;
};

struct avm_table {
    unsigned refCounter;
    avm_table_bucket* strIndexed[AVM_TABLE_HASHSIZE];
    avm_table_bucket* numIndexed[AVM_TABLE_HASHSIZE];
    unsigned total;
};


#endif
