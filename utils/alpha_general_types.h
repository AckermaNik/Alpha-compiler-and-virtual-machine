/**
 * @file alpha_target_types.h
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
 * @date 31/5/2024
*/

#ifndef ALPHA_TARGET_TYPES_H
#define ALPHA_TARGET_TYPES_H

typedef struct instruction       instruction;
typedef struct vmarg             vmarg;
typedef enum   vmarg_t           vmarg_t;
typedef enum   vmopcode          vmopcode;
typedef struct userFunc          userFunc;
typedef struct retlist           retlist;
typedef enum{false,true} bool;

enum vmopcode {
    assign_v,       add_v,          sub_v,
    mul_v,          div_v,          mod_v,
    jump_v,         jeq_v,          jne_v,
    jle_v,          jge_v,          jlt_v,
    jgt_v,          call_v,         pusharg_v,
    funcenter_v,    funcexit_v,     newtable_v,
    tablegetelem_v, tablesetelem_v,  nop_v
};

enum vmarg_t {
    label_a,
    global_a,
    formal_a,
    local_a,
    number_a,
    string_a,
    bool_a,
    nil_a,
    userfunc_a,
    libfunc_a,
    retval_a,
    invalid_a
};

struct vmarg{
    vmarg_t type;
    unsigned val;
    unsigned scope;
};

struct instruction{
    vmopcode    opcode;
    vmarg       result;
    vmarg       arg1;
    vmarg       arg2;
    unsigned    srcLine;
    unsigned    targetLine;
};

struct userFunc{
    unsigned       address;
    unsigned       localSize;
    unsigned       totalArgs;
    unsigned       scope;
    char*          id;
    retlist         *retlist;
};

struct retlist {
    unsigned int instrLabel;
    retlist* next;
};

#endif
