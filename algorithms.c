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
