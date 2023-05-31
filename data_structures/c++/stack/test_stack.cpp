#include "stack.h"

#include <iostream>
#include <assert.h>

using namespace std;


static Stack* creat_sample_stack(int size=0, int num_items=5) {
    Stack *stack = new Stack(size);
    for(int i=1; i <= num_items; i++) {
        stack->push(new Item(i));
    }
    return stack;
}


void test_can_create_stack() {

    Stack *non_sized_stack = new Stack();
    Stack *sized_stack = new Stack(10);

    assert(non_sized_stack->getSize() == 0);
    assert(non_sized_stack->getLength() == 0);
    assert(non_sized_stack->getTop() == NULL);

    assert(sized_stack->getSize() == 10);
    assert(sized_stack->getLength() == 0);
    assert(sized_stack->getTop() == NULL);

    printf("PASS: %s\n", __func__);
}


void test_can_create_item() {
    Item *item = new Item(10);

    assert(item != NULL);
    assert(item->value == 10);

    printf("PASS: %s\n", __func__);
}

void test_can_push_on_empty_stack() {
    Stack *stack = new Stack();
    Item *item = new Item(10);

    int pushed = stack->push(item);

    assert(pushed == 1);
    assert(stack->getLength() == 1);
    assert(stack->getTop()->getItem()->value == 10);

    printf("PASS: %s\n", __func__);
}


void test_can_push_on_non_empty_stack() {
    Stack *stack = creat_sample_stack(0, 5);
    Item *item = new Item(10);

    int pushed = stack->push(item);

    assert(pushed == 1);
    assert(stack->getLength() == 6);
    assert(stack->getTop()->getItem()->value == 10);

    printf("PASS: %s\n", __func__);
}


void test_cannot_push_on_full_stack() {
    Stack *stack = creat_sample_stack(5, 5);
    Item *item = new Item(10);
    int initial_stack_length = stack->getLength();

    int pushed = stack->push(item);

    assert(pushed == 0);
    assert(stack->getLength() == 5);
    assert(stack->getTop()->getItem()->value == 5);

    printf("PASS: %s\n", __func__);
}


void test_can_pop_on_empty_stack() {
    Stack *stack = new Stack();

    Item *popped = stack->pop();

    assert(popped == NULL);
    assert(stack->getLength() == 0);

    printf("PASS: %s\n", __func__);
}


void test_can_pop_on_non_empty_stack() {
    Stack *stack = creat_sample_stack(5, 5);

    Item *popped = stack->pop();

    assert(popped != NULL);
    assert(popped->value == 5);
    assert(stack->getLength() == 4);
    assert(stack->getTop()->getItem()->value == 4);

    printf("PASS: %s\n", __func__);
}


void test_can_peek_on_empty_stack() {
    Stack *stack = new Stack();

    Item *peeked = stack->peek();

    assert(peeked == NULL);
    assert(stack->getLength() == 0);

    printf("PASS: %s\n", __func__);
}


void test_can_peek_on_non_empty_stack() {
   Stack *stack = creat_sample_stack(5, 5);

    Item *peeked = stack->peek();

    assert(peeked != NULL);
    assert(stack->getLength() == 5);
    assert(stack->getTop()->getItem()->value == 5);

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