#include "queue.h"

#include <stdlib.h>


node_t* create_queue_node(item_t *item) {
    node_t *node = (node_t *) malloc(sizeof(node_t));
    node->item = item;
    node->next = NULL;

    return node;
}

queue_t* create_queue(int size) {
    queue_t *queue = (queue_t *) malloc(sizeof(queue_t));
    queue->size = size;
    queue->length = 0;
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

int enqueue(queue_t *queue, item_t *item) {
    if (queue->size == 0 || queue->length < queue->size) {
        node_t *new_node = create_queue_node(item);

        if(!queue->tail) {
            queue->head = new_node;
        } else {
            queue->tail->next = new_node;
        }

        queue->tail = new_node;
        queue->length++;
        return 0;
    }

    return 1;
}

item_t* dequeue(queue_t *queue) {
    if(!queue->head) {
        return NULL;
    }

    if(queue->head == queue->tail) {
        queue->tail = NULL;
    }

    node_t *removed = queue->head;
    item_t *item = removed->item;
    queue->head = queue->head->next;
    queue->length--;
    free(removed);

    return item;
}

item_t* peek_head(queue_t *queue) {
    if(queue->head) {
        return queue->head->item;
    }
    return NULL;
}

item_t* peek_tail(queue_t *queue) {
    if(queue->tail) {
        return queue->tail->item;
    }
    return NULL;
}

void clear(queue_t *queue) {
    while(queue->head) {
        item_t *dequeued = dequeue(queue);
        if(dequeued) {
            free(dequeued);
        }
    }
}
