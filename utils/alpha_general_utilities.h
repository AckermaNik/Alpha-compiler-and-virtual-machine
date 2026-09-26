/**
 * @file alpha_general_utilities.h
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

#ifndef ALPHA_GENERAL_UTILITIES_H
#define ALPHA_GENERAL_UTILITIES_H

#include <stdio.h>
#include <stdlib.h>
#include "alpha_general_types.h"

/**
 * Adapter for the malloc function to ensure checking of the
 * case where no memory was allocated.
 */
void* safe_malloc(size_t size);

bool streq(const char* str1, const char* str2);

char*               double_to_str(double num);
char*               int_to_str(int num);
char*               num_to_str(double num);
bool                isInt(double num);

#endif
