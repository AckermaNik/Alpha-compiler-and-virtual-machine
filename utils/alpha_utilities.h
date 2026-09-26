/**
 * @file alpha_utilities.h
 *
 * Utility library for the implementation of the alpha
 * lex analyzer.
 *
 * Created for the purposes of the lex analyzer, as part
 * of the project for HY-340, Spring 2024
 *
 * Computer science department of Crete, Greece
 *
 * -Team members: 
 * @Dimitris Segkesser
 * @Nikoleta Xenaki
 * @Vicky Miliaraki
 *
 * @date 21/2/2024
*/

#ifndef ALPHA_UTILITIES_H

#define ALPHA_UTILITIES_H

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <assert.h>
#include "alpha_general_utilities.h"

#define ASSERTIONS_ON 1
#define LOGS_ON       1

#if ASSERTIONS_ON
#define ASSERT(cond)assert(cond)
#else
#define ASSERT(cond)
#endif

#if LOGS_ON
#define LOG(tag,message,params...)printf("[%s] In file %s, line %d: "message,tag,__FILE__,__LINE__,##params);
#else
#define LOG(tag,message,params...)
#endif

char* find_special_chars(char* str);
char* getTokenName(const char* strtoken);
int   getTokenId(const char* strtoken);
struct alpha_token_list_t;
struct alpha_token_t;

struct ylval{
    int line_no;
    union{
        char*   stringVal;
        int     intVal;
        double  realVal;
    };
}ylval;


void setup_alpha_token(struct alpha_token_t* token, unsigned int lineno,unsigned int linespan, 
    unsigned int tokenno, char* content, char* category, char* type);


struct alpha_token_list_t
{
    struct alpha_token_t* head;
    struct alpha_token_t* tail;
};

struct alpha_token_t
{
    unsigned int lineno;
    unsigned int tokenno;
    unsigned int linespan;

    char*        content;
    char*        category;
    char*        type;

    struct alpha_token_t* next_token;
    struct alpha_token_t* prev_token;
};

//Global variable for the token list
struct alpha_token_list_t token_list = {NULL,NULL};

/**
 * Inserts a new token into the list
 */
void alpha_token_list_insert(struct  alpha_token_list_t* list, struct alpha_token_t* token)
{
    //Empty list
    if (list->head==NULL||list->tail==NULL)
    {
        list->head = token;
        list->tail = token;
        return;
    }

    list->tail->next_token = token;
    token->prev_token = list->tail;
    list->tail = token;
}

/**
 * Deletes the entire list completely
 */
void alpha_token_list_clear()
{
    struct alpha_token_t* iterator = token_list.head;
    while (iterator!=NULL)
    {
        if (iterator->content!=NULL)free(iterator->content);
        if (iterator->type!=NULL)free(iterator->category);
        if (iterator->type!=NULL)free(iterator->type);
        struct alpha_token_t* next = iterator->next_token;
        free(iterator);
        iterator = next;
    }

    token_list.head = NULL;
    token_list.tail = NULL;
}

/**
 * Removes a node from the list without freeing it
 */
void alpha_token_list_unlink(struct alpha_token_list_t* list, struct alpha_token_t* node)
{
    int unlink_complete = 0;

    if (node==NULL)return;

    if (node==list->tail)
    {
        list->tail = node->next_token;
        if (list->tail==NULL)
        {
            list->tail = node->prev_token;
            if(list->tail!=NULL)
                list->tail->next_token = NULL;
        }
        unlink_complete = 1;
    }

    if (node==list->head)
    {
        list->head = node->next_token;
        if(list->head!=NULL)
            list->head->prev_token = NULL;

        unlink_complete = 1;
    }

    if (unlink_complete)return;

    if(node->prev_token!=NULL)
        node->prev_token->next_token = node->next_token;

    if(node->next_token!=NULL)
        node->next_token->prev_token = node->prev_token;

    node->prev_token = NULL;
    node->next_token = NULL;
}

/**
 * Inserts a given node in such a way as to keep the list sorted based on 'tokenno'
*/
void alpha_list_insert_ordered(struct alpha_token_list_t* list, struct alpha_token_t* node)
{
    if (list==NULL||node==NULL)return;

    struct alpha_token_t* iterator = list->tail;
    struct alpha_token_t* prev = NULL;

    while (iterator!=NULL&&iterator->tokenno>node->tokenno)
    {
        prev = iterator;
        iterator = iterator->prev_token;
    }

    if (iterator==NULL)
    {
        if(prev!=NULL){
            prev->prev_token = node;
            node->next_token = prev;
            list->head = node;
            node->prev_token = NULL;
        }else{
            node->prev_token = NULL;
            node->next_token = NULL;
            list->head = node;
            list->tail = node;
        }
        return;
    }

    if(prev!=NULL)prev->prev_token = node;
    node->prev_token = iterator;
    node->next_token = iterator->next_token;
    iterator->next_token = node;

    if (iterator==list->tail)list->tail = node;
}

/**
 * Constructor for an alpha_token_t
 */
struct alpha_token_t* new_alpha_token(unsigned int lineno,unsigned int linespan, 
    unsigned int tokenno, char* content, char* category, char* type)
{
    struct alpha_token_t* new_token = (struct alpha_token_t*)safe_malloc(sizeof(struct alpha_token_t));
    setup_alpha_token(new_token,lineno,linespan,tokenno,content,category,type);
    return new_token;
}

void setup_alpha_token(struct alpha_token_t* token, unsigned int lineno,unsigned int linespan, 
    unsigned int tokenno, char* content, char* category, char* type)
{
    ASSERT(token!=NULL);

    token->lineno = lineno;
    token->tokenno = tokenno;
    token->linespan = linespan;

    //Perform a deep copy for the strings
    int str_size;
    char* dup_str;

    str_size = strlen(content);
    dup_str = (char*)safe_malloc(sizeof(char)*(str_size+1));
    memcpy(dup_str,content,str_size+1);
    token->content = dup_str;

    str_size = strlen(type);
    dup_str = (char*)safe_malloc(sizeof(char)*(str_size+1));
    memcpy(dup_str,type,str_size+1);
    token->type = dup_str;

    str_size = strlen(category);
    dup_str = (char*)safe_malloc(sizeof(char)*(str_size+1));
    memcpy(dup_str,category,str_size+1);
    token->category = dup_str;
    //

    token->next_token = NULL;
    token->prev_token = NULL;
}

/**
 * Gets a new element from the token list by using a starting node
 * and an offset (positive or negative) to traverse the list.
 * @return The element, if found, NULL otherwise.
 */
struct alpha_token_t* alpha_list_seek(struct alpha_token_t* from, int seek_distance)
{
    if (from==NULL)return NULL;

    if (seek_distance>0)
    {
        while (seek_distance>0)
        {
            if (from==NULL)return NULL;
            from = from->next_token;
            seek_distance--;
        }
    }
    else if (seek_distance<0)
    {
        while (seek_distance<0)
        {
            if (from==NULL)return NULL;
            from = from->prev_token;
            seek_distance++;
        }
    }else return from;

    return from;
}

/**
 * Prints the contents of the given list.
 * **For debugging purposes only!**
 *
*/
void printList(struct alpha_token_list_t list)
{
    struct alpha_token_t* head = list.head;
    printf("=======================\n");
    while (head!=NULL)
    {
        printf("line: %d, token: %d, content: %s, type: %s\n",head->lineno,head->tokenno,head->content,head->type);
        head = head->next_token;
    }
    printf("======END OF LOG=======\n");
}

#endif
