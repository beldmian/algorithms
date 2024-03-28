#include "binary_heap.h"

MaxBinaryHeap *make_binary_heap() {
  MaxBinaryHeap *heap = malloc(sizeof(MaxBinaryHeap));
  heap->data = malloc(sizeof(BINARY_HEAP_TYPE) * BINARY_HEAP_SIZE);
  heap->len = 0;
  return heap;
}

void binary_heap_push(MaxBinaryHeap *heap, BINARY_HEAP_TYPE value) {
  if (heap->len == BINARY_HEAP_SIZE) {
    heap->data = realloc(heap->data, sizeof(BINARY_HEAP_TYPE) * heap->len * 2);
  }
  heap->data[heap->len] = value;
  heap->len++;
  int i = heap->len - 1;
  while (i > 0 && heap->data[i] > heap->data[(i - 1) / 2]) {
    BINARY_HEAP_TYPE tmp = heap->data[i];
    heap->data[i] = heap->data[(i - 1) / 2];
    heap->data[(i - 1) / 2] = tmp;
    i = (i - 1) / 2;
  }
}

BINARY_HEAP_TYPE binary_heap_pop(MaxBinaryHeap *heap) {
  if (heap->len == 0) {
    return 0;
  }
  BINARY_HEAP_TYPE ret = heap->data[0];
  heap->data[0] = heap->data[heap->len - 1];
  heap->len--;
  int i = 0;
  while (heap->len > i * 2 + 1) {
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    int max = i;
    if (heap->data[max] < heap->data[left]) {
      max = left;
    }
    if (heap->data[max] < heap->data[right]) {
      max = right;
    }
    if (max != i) {
      BINARY_HEAP_TYPE tmp = heap->data[i];
      heap->data[i] = heap->data[max];
      heap->data[max] = tmp;
      i = max;
    } else {
      break;
    }
  }
  return ret;
}

BINARY_HEAP_TYPE binary_heap_max(MaxBinaryHeap *heap) { return heap->data[0]; }

void free_binary_heap(MaxBinaryHeap *heap) {
  free(heap->data);
  free(heap);
}
