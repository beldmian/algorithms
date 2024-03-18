#pragma once

#include "stddef.h"
#include "stdlib.h"

#define BINARY_SEARCH_TYPE unsigned long

long long binary_search(BINARY_SEARCH_TYPE *array, size_t len,
                        BINARY_SEARCH_TYPE value);
