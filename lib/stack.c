#include "stack.h"
#include "common.h"

Stack *make_stack() {
  Stack *stack = malloc(sizeof(Stack));
  ASSERT_PTR(stack);
  stack->elements = malloc(sizeof(STACK_TYPE) * DEFAULT_STACK_SIZE);
  ASSERT_PTR(stack->elements);
  stack->len = 0;
  stack->size = DEFAULT_STACK_SIZE;
  return stack;
}

void stack_push(Stack *stack, STACK_TYPE element) {
  stack->len++;
  if (stack->len > stack->size) {
    stack->size *= 2;
    stack->elements =
        realloc(stack->elements, sizeof(STACK_TYPE) * stack->size);
    ASSERT_PTR(stack->elements);
  }
  stack->elements[stack->len] = element;
}

STACK_TYPE stack_pop(Stack *stack) {
  stack->len--;
  return stack->elements[stack->len + 1];
}

void free_stack(Stack *stack) {
  free(stack->elements);
  free(stack);
}
