#include "algorithms.h"
#include "binary_heap.h"
#include "graph.h"
#include "linked_list.h"
#include "queue.h"
#include "stack.h"

#include "stdio.h"
#include "stdlib.h"

void test_linked_list() {
  LIST_TYPE *data = malloc(sizeof(LIST_TYPE) * 10);
  for (int i = 0; i < 10; i++) {
    data[i] = i;
  }
  LinkedListNode *root = list_from_array(data, 10);
  while (root != NULL) {
    printf("%d\n", (int)root->value);
    root = root->next;
  }
  free(data);
  free_list(root);
}

void test_stack() {
  Stack *s = make_stack();
  for (int i = 0; i < 20; i++) {
    stack_push(s, i);
  }
  for (int i = 0; i < 20; i++) {
    printf("%lu\n", stack_pop(s));
  }
  free_stack(s);
}

void test_queue() {
  Queue *q = make_queue();
  for (int i = 0; i < 20; i++) {
    queue_push(q, i);
  }
  for (int i = 0; i < 20; i++) {
    printf("%lu\n", queue_pop(q));
  }
  free_queue(q);
}

void test_binary_search() {
  size_t test_length = 1000000;
  BINARY_SEARCH_TYPE *data = malloc(sizeof(BINARY_SEARCH_TYPE) * test_length);
  for (int i = 0; i < test_length; i++) {
    data[i] = i;
  }
  printf("100: %lli\n", binary_search(data, test_length, 100));
  printf("1243: %lli\n", binary_search(data, test_length, 1243));
  printf("10000000: %lli\n", binary_search(data, test_length, 10000000));
  free(data);
}

void test_binary_heap() {
  MaxBinaryHeap *heap = make_binary_heap();
  for (int i = 0; i < 10; i++) {
    binary_heap_push(heap, i);
  }
  for (int i = 0; i < 10; i++) {
    printf("%lu\n", heap->data[i]);
  }
  printf("Max: %lu\n", binary_heap_pop(heap));
  for (int i = 0; i < 9; i++) {
    printf("%lu\n", heap->data[i]);
  }
  free_binary_heap(heap);
}

void test_binary_heap_sort() {
  BINARY_HEAP_TYPE array[] = {2, 1, 4, 3, 7, 6, 5, 8, 9, 10};
  binary_heap_sort(array, 10);
  for (int i = 0; i < 10; i++) {
    printf("%lu\n", array[i]);
  }
}

void test_quick_sort() {
  QUICK_SORT_TYPE array[] = {2, 1, 4, 3, 7, 6, 5, 8, 9, 10};
  quick_sort(array, 10);
  for (int i = 0; i < 10; i++) {
    printf("%lu\n", array[i]);
  }
}

void test_graph_dfs() {
  MatrixGraph *graph = make_matrix_graph(4);
  GraphVisitor *visitor = make_print_visitor();
  matrix_graph_set_edge(graph, 0, 1, 1);
  matrix_graph_set_edge(graph, 1, 3, 1);
  matrix_graph_set_edge(graph, 0, 2, 1);

  dfs(graph, visitor, 0);

  free_matrix_graph(graph);
  free_graph_visitor(visitor);
}

int main(int argc, char *argv[]) {
  printf("Linked List\n");
  test_linked_list();
  printf("Stack\n");
  test_stack();
  printf("Queue\n");
  test_queue();
  printf("Binary Search\n");
  test_binary_search();
  printf("Binary Heap\n");
  test_binary_heap();
  printf("Quick Sort\n");
  test_quick_sort();
  printf("DFS\n");
  test_graph_dfs();
  return EXIT_SUCCESS;
}
