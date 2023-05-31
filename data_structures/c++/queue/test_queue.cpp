#include "queue.h"
#include "item.h"

#include <assert.h>
#include <iostream>

using namespace std;


void assert_empty_queue(Queue queue) {
    assert(queue.getLength() == 0);
    assert(queue.getHead() == NULL);
    assert(queue.getTail() == NULL);
}

void test_can_create_item() {
    Item *item = new Item(22);

    assert(item != NULL);
    assert(item->value == 22);

    printf("✅ PASS: %s\n", __func__);
}


void test_can_create_queue_node() {
    Item *item = new Item(22);
    Node *node = new Node(item);

    assert(node != NULL);
    assert(node->getNext() == NULL);
    assert(node->getItem()->value = 22);

    printf("✅ PASS: %s\n", __func__);
}


void test_can_create_non_sized_queue() {
    Queue *queue = new Queue();

    assert_empty_queue(*queue);

    printf("✅ PASS: %s\n", __func__);
}


void test_can_create_sized_queue() {
    int expected_queue_size = 10;
    Queue *queue = new Queue(expected_queue_size);

    assert(queue->getSize() == expected_queue_size);
    assert_empty_queue(*queue);

    printf("✅ PASS: %s\n", __func__);
}


void test_can_enqueue_on_empty_queue() {
    Queue *queue = new Queue();
    Item *item = new Item(15);

    int error = queue->enqueue(item);

    assert(!error);
    assert(queue->getLength() == 1);
    assert(queue->getHead() == queue->getTail());
    assert(queue->getHead()->getItem()->value == 15);

    printf("✅ PASS: %s\n", __func__);
}


void test_can_enqueue_on_non_empty_queue() {
    Queue *queue = new Queue();

    queue->enqueue(new Item(15));
    queue->enqueue(new Item(16));
    queue->enqueue(new Item(17));
    queue->enqueue(new Item(18));

    int error = queue->enqueue(new Item(19));

    assert(!error);
    assert(queue->getLength() == 5);
    assert(queue->getHead() != queue->getTail());
    assert(queue->getHead()->getItem()->value == 15);
    assert(queue->getHead()->getNext()->getItem()->value == 16);
    assert(queue->getHead()->getNext()->getNext()->getItem()->value == 17);
    assert(queue->getHead()->getNext()->getNext()->getNext()->getItem()->value == 18);
    assert(queue->getHead()->getNext()->getNext()->getNext()->getNext()->getItem()->value == 19);
    assert(queue->getTail()->getItem()->value == 19);

    printf("✅ PASS: %s\n", __func__);
}


void test_cannot_enqueue_on_full_empty_queue() {
    Queue *queue = new Queue(4);

    queue->enqueue(new Item(15));
    queue->enqueue(new Item(16));
    queue->enqueue(new Item(17));
    queue->enqueue(new Item(18));

    int error = queue->enqueue(new Item(19));

    assert(error);
    assert(queue->getLength() == queue->getSize());
    assert(queue->getHead()->getItem()->value == 15);
    assert(queue->getTail()->getItem()->value == 18);
}


void test_can_dequeue_on_empty_queue() {
    Queue *queue = new Queue();

    Item *dequeued = queue->dequeue();

    assert(dequeued == NULL);
    assert_empty_queue(*queue);

    printf("✅ PASS: %s\n", __func__);
}


void test_can_dequeue_on_non_empty_queue() {
    Queue *queue = new Queue();

    queue->enqueue(new Item(15));
    queue->enqueue(new Item(16));
    queue->enqueue(new Item(17));
    queue->enqueue(new Item(18));

    Item *dequeued = queue->dequeue();

    assert(dequeued != NULL);
    assert(dequeued->value == 15);
    assert(queue->getLength() == 3);
    assert(queue->getHead()->getItem()->value == 16);

    printf("✅ PASS: %s\n", __func__);
}


void test_can_peek_at_head_on_empty_queue() {
    Queue *queue = new Queue();

    Item *peeked = queue->peek_head();

    assert(peeked == NULL);
    assert_empty_queue(*queue);

    printf("✅ PASS: %s\n", __func__);
}


void test_can_peek_at_head_on_non_empty_queue() {
    Queue *queue = new Queue();

    queue->enqueue(new Item(15));
    queue->enqueue(new Item(16));
    queue->enqueue(new Item(17));
    queue->enqueue(new Item(18));

    Item *peeked = queue->peek_head();

    assert(peeked != NULL);
    assert(peeked->value == 15);
    assert(queue->getLength() == 4);
    assert(queue->getHead()->getItem()->value == 15);

    printf("✅ PASS: %s\n", __func__);
}


void test_can_peek_at_tail_on_empty_queue() {
    Queue *queue = new Queue();

    Item *peeked = queue->peek_tail();

    assert(peeked == NULL);
    assert_empty_queue(*queue);

    printf("✅ PASS: %s\n", __func__);
}


void test_can_peek_at_tail_on_non_empty_queue() {
    Queue *queue = new Queue();

    queue->enqueue(new Item(15));
    queue->enqueue(new Item(16));
    queue->enqueue(new Item(17));
    queue->enqueue(new Item(18));

    Item *peeked = queue->peek_tail();

    assert(peeked != NULL);
    assert(peeked->value == 18);
    assert(queue->getLength() == 4);
    assert(queue->getTail()->getItem()->value == 18);

    printf("✅ PASS: %s\n", __func__);
}


void test_can_clear_empty_queue() {
    Queue *queue = new Queue();

    queue->clear();

    assert_empty_queue(*queue);

    printf("✅ PASS: %s\n", __func__);
}


void test_can_clear_non_empty_queue() {
    Queue *queue = new Queue();

    queue->enqueue(new Item(15));
    queue->enqueue(new Item(16));
    queue->enqueue(new Item(17));
    queue->enqueue(new Item(18));

    queue->clear();

    assert_empty_queue(*queue);

    printf("✅ PASS: %s\n", __func__);
}



int main() {
    test_can_create_item();
    test_can_create_queue_node();
    test_can_create_non_sized_queue();
    test_can_create_sized_queue();
    test_can_enqueue_on_empty_queue();
    test_can_enqueue_on_non_empty_queue();
    test_cannot_enqueue_on_full_empty_queue();
    test_can_dequeue_on_empty_queue();
    test_can_dequeue_on_non_empty_queue();
    test_can_peek_at_head_on_empty_queue();
    test_can_peek_at_head_on_non_empty_queue();
    test_can_peek_at_tail_on_empty_queue();
    test_can_peek_at_tail_on_non_empty_queue();
    test_can_clear_empty_queue();
    test_can_clear_non_empty_queue();
}