#include "stack.h"

#include <stdio.h>
#include <assert.h>


static lstack_t* creat_sample_stack(int size, int num_items) {
    lstack_t *stack = create_stack(size);
    for(int i=1; i <= num_items; i++) {
        push_on_stack(stack, create_item(i));
    }
    return stack;
}


void test_can_create_stack() {

    lstack_t *no_size_stack = create_stack(0);
    lstack_t *sized_stack = create_stack(10);

    assert(no_size_stack->size == 0);
    assert(no_size_stack->length == 0);
    assert(no_size_stack->top == NULL);

    assert(sized_stack->size == 10);
    assert(sized_stack->length == 0);
    assert(sized_stack->top == NULL);

    printf("PASS: %s\n", __func__);
}


void test_can_create_item() {
    item_t *item = create_item(10);

    assert(item != NULL);
    assert(item->value == 10);

    printf("PASS: %s\n", __func__);
}

void test_can_push_on_empty_stack() {
    lstack_t *stack = create_stack(0);
    item_t *item = create_item(10);

    int pushed = push_on_stack(stack, item);

    assert(pushed == 1);
    assert(stack->length == 1);
    assert(stack->top->item->value == 10);

    printf("PASS: %s\n", __func__);
}


void test_can_push_on_non_empty_stack() {
    lstack_t *stack = creat_sample_stack(0, 5);
    item_t *item = create_item(10);
    int initial_stack_length = stack->length;

    int pushed = push_on_stack(stack, item);

    assert(pushed == 1);
    assert(stack->length == 6);
    assert(stack->top->item->value == 10);

    printf("PASS: %s\n", __func__);
}


void test_cannot_push_on_full_stack() {
    lstack_t *stack = creat_sample_stack(5, 5);
    item_t *item = create_item(10);
    int initial_stack_length = stack->length;

    int pushed = push_on_stack(stack, item);

    assert(pushed == 0);
    assert(stack->length == 5);
    assert(stack->top->item->value == 5);

    printf("PASS: %s\n", __func__);
}


void test_can_pop_on_empty_stack() {
    lstack_t *stack = create_stack(0);

    item_t *popped = pop_on_stack(stack);

    assert(popped == NULL);
    assert(stack->length == 0);

    printf("PASS: %s\n", __func__);
}


void test_can_pop_on_non_empty_stack() {
    lstack_t *stack = creat_sample_stack(5, 5);

    item_t *popped = pop_on_stack(stack);

    assert(popped != NULL);
    assert(popped->value == 5);
    assert(stack->length == 4);
    assert(stack->top->item->value == 4);

    printf("PASS: %s\n", __func__);
}


void test_can_peek_on_empty_stack() {
    lstack_t *stack = create_stack(0);

    item_t *peeked = peek_on_stack(stack);

    assert(peeked == NULL);
    assert(stack->length == 0);

    printf("PASS: %s\n", __func__);
}


void test_can_peek_on_non_empty_stack() {
   lstack_t *stack = creat_sample_stack(5, 5);

    item_t *peeked = peek_on_stack(stack);

    assert(peeked != NULL);
    assert(stack->length == 5);
    assert(stack->top->item->value == 5);

    printf("PASS: %s\n", __func__);
}


int main() {
    test_can_create_stack();
    test_can_create_item();
    test_can_push_on_empty_stack();
    test_can_push_on_non_empty_stack();
    test_cannot_push_on_full_stack();
    test_can_pop_on_empty_stack();
    test_can_pop_on_non_empty_stack();
    test_can_peek_on_empty_stack();
    test_can_peek_on_non_empty_stack();
}