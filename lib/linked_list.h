#pragma once

#include "stddef.h"
#include "stdlib.h"

#define LIST_TYPE unsigned long

typedef struct LinkedListNode {
  LIST_TYPE value;
  struct LinkedListNode *next;
  struct LinkedListNode *prev;
} LinkedListNode;

LinkedListNode *new_list_node(LIST_TYPE value);
LinkedListNode *list_from_array(LIST_TYPE *array, size_t len);
void free_list(LinkedListNode *root);
