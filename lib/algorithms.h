#pragma once

#include "binary_heap.h"
#include "stddef.h"
#include "stdlib.h"

#define BINARY_SEARCH_TYPE unsigned long
long long binary_search(BINARY_SEARCH_TYPE *array, size_t len,
                        BINARY_SEARCH_TYPE value);

#define QUICK_SORT_TYPE unsigned long
void quick_sort(QUICK_SORT_TYPE *array, size_t len);

void binary_heap_sort(BINARY_HEAP_TYPE *array, size_t len);
