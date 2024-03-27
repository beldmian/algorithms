#pragma once

#include "stdlib.h"

#define BINARY_HEAP_TYPE unsigned long
#define BINARY_HEAP_SIZE 100

typedef struct MaxBinaryHeap {
  BINARY_HEAP_TYPE *data;
  size_t len;
} MaxBinaryHeap;

MaxBinaryHeap *make_binary_heap();
void binary_heap_push(MaxBinaryHeap *heap, BINARY_HEAP_TYPE value);
BINARY_HEAP_TYPE binary_heap_pop(MaxBinaryHeap *heap);
BINARY_HEAP_TYPE binary_heap_max(MaxBinaryHeap *heap);
void free_binary_heap(MaxBinaryHeap *heap);
