#ifndef STACK_H_
#define STACK_H_

#include "item.h"

typedef struct node {
    item_t *item;
    struct node *next;
} node_t;

typedef struct stack {
    node_t *top;
    int size;
    int length;
} lstack_t;


lstack_t* create_stack(int size);

int push_on_stack(lstack_t *stack, item_t *item);
item_t* pop_on_stack(lstack_t *stack);
item_t* peek_on_stack(lstack_t *stack);

#endif /* STACK_H_ */