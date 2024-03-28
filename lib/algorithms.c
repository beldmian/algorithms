#include "algorithms.h"

long long binary_search(BINARY_SEARCH_TYPE *array, size_t len,
                        BINARY_SEARCH_TYPE value) {
  int l = 0;
  int r = len - 1;
  while (l <= r) {
    int m = (l + r) / 2;
    if (array[m] == value) {
      return m;
    } else if (array[m] < value) {
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  return -1;
}

size_t quick_sort_partition(QUICK_SORT_TYPE *array, size_t start, size_t end) {
  QUICK_SORT_TYPE pivot = array[end];
  size_t ind = start - 1;
  for (size_t i = start; i < end; i++) {
    if (array[i] <= pivot) {
      ind++;
      QUICK_SORT_TYPE temp = array[ind];
      array[ind] = array[i];
      array[i] = temp;
    }
  }
  ind++;
  QUICK_SORT_TYPE temp = array[ind];
  array[ind] = array[end];
  array[end] = temp;
  return ind;
}

void quick_sort_inner(QUICK_SORT_TYPE *array, size_t start, size_t end) {
  if (end <= start || start < 0) {
    return;
  }
  size_t p = quick_sort_partition(array, start, end);
  if (p != 0) {
    quick_sort_inner(array, start, p - 1);
  }
  quick_sort_inner(array, p + 1, end);
}

void quick_sort(QUICK_SORT_TYPE *array, size_t len) {
  quick_sort_inner(array, 0, len - 1);
}

void binary_heap_sort(BINARY_HEAP_TYPE *array, size_t len) {
  MaxBinaryHeap *heap = make_binary_heap();
  for (int i = 0; i < len; i++) {
    binary_heap_push(heap, array[i]);
  }
  for (int i = 0; i < len; i++) {
    array[i] = binary_heap_pop(heap);
  }
  free_binary_heap(heap);
}
