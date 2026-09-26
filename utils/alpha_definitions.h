/**
 * @file alpha_definitions.h
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
 * @date 31/5/2024
*/

#ifndef ALPHA_DEFINITIONS_H
#define ALPHA_DEFINITIONS_H

#include <assert.h>

#define ASSERTIONS_ON     1
#define LOGS_ON           1
#define ERRORS_ON         1
#define AVMERRORS_ON      1
#define AVMWARNING_ON      1
#define USER_ERRORS_ON    1
#define GENERAL_ERRORS_ON 1
#define ENABLE_COLORS     1

#define AVM_STACKSIZE 4096
#define AVM_WIPEOUT(m) memset(&(m), 0, sizeof(m))
#define AVM_TABLE_HASHSIZE 211
#define AVM_ENDING_PC       codeSize
#define AVM_MAX_INSTRUCTIONS 21
#define AVM_STACKENV_SIZE    4

#define AVM_NUMACTUALS_OFFSET 4
#define AVM_SAVEDPC_OFFSET 3
#define AVM_SAVEDTOP_OFFSET 2
#define AVM_SAVEDTOPSP_OFFSET 1

#define execute_add execute_arithmetic
#define execute_sub execute_arithmetic
#define execute_mod execute_arithmetic
#define execute_div execute_arithmetic
#define execute_mul execute_arithmetic

#define execute_jle execute_jcomparison
#define execute_jge execute_jcomparison
#define execute_jlt execute_jcomparison
#define execute_jgt execute_jcomparison

#define ERR_CORRUPT_FILE() \
    fprintf(stderr, "Error, corrupt input file\n")



#if ASSERTIONS_ON
#define ASSERT(cond)assert(cond)
#else
#define ASSERT(cond)
#endif

#if ENABLE_COLORS
#define PRINT_RED(message, params...) printf("\033[0;31m"message"\033[0m",##params)
#define PRINT_YELLOW(message, params...) printf("\033[0;33m"message"\033[0m",##params)
#define PRINT_PURPLE(message, params...) printf("\033[0;35m"message"\033[0m",##params),error_found = true
#else
#define PRINT_RED(message, params...) printf(message,##params)
#define PRINT_YELLOW(message, params...) printf(message,##params)
#define PRINT_PURPLE(message, params...) printf(message,##params)
#endif

#if LOGS_ON
#define LOG(tag,message,params...)printf("[%s] In file %s, line %d: "message,tag,__FILE__,__LINE__,##params)
#else
#define LOG(tag,message,params...)
#endif

#if AVMERRORS_ON
#define avm_error(message,params...)printf("\033[0;31m[AVM ERROR] In line %d: "message"\033[0m",code[pc].srcLine,##params),exit(EXIT_FAILURE)
#else
#define avm_error(message,params...)
#endif

#if AVMWARNING_ON
#define avm_warning(message,params...)printf("\033[0;33m[AVM WARNING]: "message"\033[0m",##params)
#else
#define avm_warning(message,params...)
#endif

#if ERRORS_ON
#define ERROR(message,params...)printf("\033[0;35m[INTERNAL ERROR] In file %s, line %d: "message"\033[0m",__FILE__,__LINE__,##params),exit(EXIT_FAILURE)
#else
#define ERROR(message,params...)
#endif

#if USER_ERRORS_ON
#define USER_ERROR(message,params...)printf("\033[0;31m[ERROR] In file %s, line %d: "message"\033[0m",in_filename,yylineno,##params),error_found = true
#else
#define USER_ERROR(message,params...)
#endif

#if GENERAL_ERRORS_ON
#define GENERAL_ERROR(message,params...)printf("\033[0;31m[ERROR] In file %s: "message"\033[0m",in_filename,##params)
#else
#define GENERAL_ERROR(message,params...)
#endif

#endif
