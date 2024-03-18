#include "linked_list.h"

LinkedListNode *new_list_node(LIST_TYPE value) {
  LinkedListNode *node = malloc(sizeof(LinkedListNode));
  node->value = value;
  return node;
}

LinkedListNode *list_from_array(LIST_TYPE *array, size_t len) {
  if (len == 0) {
    return NULL;
  }
  LinkedListNode *root = malloc(sizeof(LinkedListNode));
  root->value = array[0];
  root->prev = NULL;
  LinkedListNode *prev = root;
  for (int i = 1; i < len; i++) {
    LinkedListNode *new_node = malloc(sizeof(LinkedListNode));
    new_node->value = array[i];
    new_node->prev = prev;
    prev->next = new_node;
    prev = new_node;
  }
  return root;
}

void free_list(LinkedListNode *root) {
  if (root != NULL) {
    free_list(root->next);
    free(root);
  }
}