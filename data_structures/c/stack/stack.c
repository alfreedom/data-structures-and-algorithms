#include "stack.h"

#include <stdlib.h>


static node_t* create_node(item_t *item) {
    node_t *node = (node_t *) malloc(sizeof(node_t));
    node->item = item;
    node->next = NULL;

    return node;
}

lstack_t* create_stack(int size) {
    lstack_t *stack = (lstack_t *) malloc(sizeof(lstack_t));
    stack->size = size;
    stack->top = NULL;
    stack->length = 0;

    return stack;
}

int push_on_stack(lstack_t *stack, item_t *item) {
    if(stack->size == 0 || stack->length < stack->size) {
        node_t *new_node = create_node(item);
        new_node->next = stack->top;
        stack->top = new_node;
        stack->length++;
        return 1;
    }

    return 0;
}

item_t* pop_on_stack(lstack_t *stack) {
    item_t *item = NULL;
    if(stack->top) {
        node_t *removed = stack->top;
        stack->top = removed->next;
        item = removed->item;
        stack->length--;
        free(removed);
    }
    return item;
}

item_t* peek_on_stack(lstack_t *stack) {
    if(stack->top) {
        return stack->top->item;
    }
    return NULL;
}