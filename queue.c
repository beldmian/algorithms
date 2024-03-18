#include "queue.h"

Queue *make_queue() {
  Queue *queue = malloc(sizeof(Queue));
  queue->start = NULL;
  queue->end = NULL;
  return queue;
}

void queue_push(Queue *queue, QUEUE_TYPE element) {
  LinkedListNode *node = new_list_node(element);
  if (queue->start == NULL) {
    queue->start = node;
  } else {
    queue->end->next = node;
  }
  queue->end = node;
}

QUEUE_TYPE queue_pop(Queue *queue) {
  LinkedListNode *node = queue->start;
  QUEUE_TYPE value = node->value;
  queue->start = node->next;
  free(node);
  return value;
}

void free_queue(Queue *queue) {
  free_list(queue->start);
  free(queue);
}
