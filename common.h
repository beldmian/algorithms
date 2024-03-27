#pragma once

#include "stdlib.h"

#define ASSERT_PTR(ptr)                                                        \
  if ((ptr) == NULL) {                                                         \
    exit(1);                                                                   \
  }
