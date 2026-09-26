/**
 * @file alpha_general_utilities.c
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

#include "alpha_general_utilities.h"
#include "alpha_definitions.h"
#include <string.h>

void* safe_malloc(size_t size)
{
    void* allocated = malloc(size);
    if (allocated == NULL)
    {
        fprintf(stderr,"Unable to allocate memory.\n");
        exit(EXIT_FAILURE);
    }
    return allocated;
}

bool streq(const char* str1, const char* str2)
{
    ASSERT(str1!=NULL);
    ASSERT(str2!=NULL);

    return (strcmp(str1,str2)==0);
}

char* double_to_str(double num){
    int num_len = snprintf(NULL, 0, "%f", num) + 1; // +1 for the null terminator
    char* name = safe_malloc((int)num_len*sizeof(char*));
    sprintf(name, "%f", num);
    return name;
}

char* num_to_str(double num){
    if(isInt(num))
        return int_to_str(num);
    return double_to_str(num);
}

bool isInt(double num){
    return (num==(int)num);
}

char* int_to_str(int num){
    int num_len = snprintf(NULL, 0, "%d", num) + 1; // +1 for the null terminator
    char* name = safe_malloc((int)num_len*sizeof(char*));
    sprintf(name, "%d", num);
    return name;
}
