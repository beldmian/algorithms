#pragma once

#include "stddef.h"
#include "stdlib.h"

#define DEFAULT_STACK_SIZE 16
#define STACK_TYPE unsigned long

typedef struct Stack {
  STACK_TYPE *elements;
  size_t len;
  size_t size;
} Stack;

Stack *make_stack();
void stack_push(Stack *stack, STACK_TYPE element);
STACK_TYPE stack_pop(Stack *stack);
void free_stack(Stack *stack);
