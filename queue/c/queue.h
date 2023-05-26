#ifndef QUEUE_H_
#define QUEUE_H_

#include "item.h"

typedef struct node {
    item_t *item;
    struct node *next;
} node_t;


typedef struct queue {
    int size;
    int length;
    node_t *head;
    node_t *tail;
} queue_t;


node_t* create_queue_node(item_t *item);
queue_t* create_queue(int size);

int enqueue(queue_t *queue, item_t *item);
item_t* dequeue(queue_t *queue);
item_t* peek_head(queue_t *queue);
item_t* peek_tail(queue_t *queue);
void clear(queue_t *queue);

#endif /* QUEUE_H_ */