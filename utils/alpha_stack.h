/**
 * @file alpha_stack.h
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
 * @date 6/2/2024
*/

#ifndef ALPHA_STACK_H
#define ALPHA_STACK_H

#include "alpha_definitions.h"
#include "alpha_general_utilities.h"

typedef struct Stack_elem       *Stack_elem_t;
typedef struct Stack            *Stack_t;

struct Stack_elem {
    int value;
    Stack_elem_t next;
};

struct Stack {
    Stack_elem_t top;
    int size;
};

Stack_elem_t        new_Stack_elem(int _value);
Stack_t             new_Stack();

void                delete_Stack_elem(Stack_elem_t obj);
void                Stack_push(Stack_t stack, int val);
int                 Stack_pop(Stack_t stack);
int                 Stack_peek(Stack_t stack);
int                 Stack_lookup(Stack_t stack, int index);



Stack_elem_t new_Stack_elem(int _value){
    Stack_elem_t new_obj = (Stack_elem_t)safe_malloc(sizeof(struct Stack_elem));
    new_obj->value = _value;
    return new_obj;
}

void delete_Stack_elem(Stack_elem_t obj){
    free(obj);
}

Stack_t new_Stack(){
    Stack_t new_obj = (Stack_t)safe_malloc(sizeof(struct Stack));
    new_obj->top = NULL;
    new_obj->size = 0;
    return new_obj;
}

void Stack_push(Stack_t stack, int val){
    Stack_elem_t new_elem = new_Stack_elem(val);
    new_elem->next = stack->top;
    stack->top = new_elem;
    stack->size++;
}

int Stack_pop(Stack_t stack){
    if(stack->size>0){
        stack->size--;
        Stack_elem_t old_top = stack->top;
        int old_val = old_top->value;
        stack->top = stack->top->next;
        delete_Stack_elem(old_top);
        return old_val;
    }
    ERROR("Attempting to pop empty stack!\n");
}

int Stack_peek(Stack_t stack){
    if(stack->size>0){
        return stack->top->value;
    }
    ERROR("Attempting to peek empty stack!\n");
}

#endif
