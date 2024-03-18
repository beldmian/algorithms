#include "algorithms.h"
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

/* Binary Heap */
#define BINARY_HEAP_TYPE unsigned long
#define BINARY_HEAP_SIZE 100

typedef struct MaxBinaryHeap {
  BINARY_HEAP_TYPE *data;
  size_t len;
} MaxBinaryHeap;

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

/* Binary Heap Sort */
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

void test_binary_heap_sort() {
  BINARY_HEAP_TYPE array[] = {2, 1, 4, 3, 7, 6, 5, 8, 9, 10};
  binary_heap_sort(array, 10);
  for (int i = 0; i < 10; i++) {
    printf("%lu\n", array[i]);
  }
}

/* Quick sort */
#define QUICK_SORT_TYPE unsigned long

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

void test_quick_sort() {
  QUICK_SORT_TYPE array[] = {2, 1, 4, 3, 7, 6, 5, 8, 9, 10};
  quick_sort(array, 10);
  for (int i = 0; i < 10; i++) {
    printf("%lu\n", array[i]);
  }
}

/* Graph */
#define MATRIX_GRAPH_EDGE_TYPE unsigned long

typedef struct MatrixGraph {
  size_t verts_count;
  MATRIX_GRAPH_EDGE_TYPE **edges_matrix;
} MatrixGraph;

MatrixGraph *make_matrix_graph(size_t verts_count) {
  MatrixGraph *graph = malloc(sizeof(MatrixGraph));
  graph->verts_count = verts_count;
  graph->edges_matrix = calloc(verts_count, sizeof(int *));
  for (int i = 0; i < verts_count; i++) {
    graph->edges_matrix[i] = calloc(verts_count, sizeof(int));
  }
  return graph;
}

void matrix_graph_set_edge(MatrixGraph *graph, size_t from, size_t to,
                           MATRIX_GRAPH_EDGE_TYPE edge) {
  graph->edges_matrix[from][to] = edge;
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
  return EXIT_SUCCESS;
}
