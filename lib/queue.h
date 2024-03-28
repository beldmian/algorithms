#pragma once

#include "linked_list.h"
#include "stddef.h"
#include "stdlib.h"

#define QUEUE_TYPE unsigned long

typedef struct Queue {
  LinkedListNode *start;
  LinkedListNode *end;
} Queue;

Queue *make_queue();
void queue_push(Queue *queue, QUEUE_TYPE element);
QUEUE_TYPE queue_pop(Queue *queue);
void free_queue(Queue *queue);
