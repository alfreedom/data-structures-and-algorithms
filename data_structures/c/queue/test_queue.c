#include "queue.h"
#include "item.h"

#include <stdio.h>
#include <assert.h>


void assert_empty_queue(queue_t queue) {
    assert(queue.length == 0);
    assert(queue.head == NULL);
    assert(queue.tail == NULL);
}

void test_can_create_item() {
    item_t *item = create_item(22);

    assert(item != NULL);
    assert(item->value == 22);

    printf("✅ PASS: %s\n", __func__);
}


void test_can_create_queue_node() {
    item_t *item = create_item(10);
    node_t *node = create_queue_node(item);

    assert(node->item->value = 10);
    assert(node->next == NULL);

    printf("✅ PASS: %s\n", __func__);
}


void test_can_create_non_sized_queue() {
    queue_t *queue = create_queue(0);

    assert_empty_queue(*queue);

    printf("✅ PASS: %s\n", __func__);
}


void test_can_create_sized_queue() {
    int expected_queue_size = 5;
    queue_t *queue = create_queue(expected_queue_size);

    assert(queue->size == expected_queue_size);
    assert_empty_queue(*queue);

    printf("✅ PASS: %s\n", __func__);
}


void test_can_enqueue_on_empty_queue() {
    queue_t *queue = create_queue(0);
    item_t *item = create_item(15);

    int error = enqueue(queue, item);

    assert(!error);
    assert(queue->length == 1);
    assert(queue->head == queue->tail);
    assert(queue->head->item->value == 15);

    printf("✅ PASS: %s\n", __func__);
}


void test_can_enqueue_on_non_empty_queue() {
    queue_t *queue = create_queue(0);

    enqueue(queue, create_item(15));
    enqueue(queue, create_item(16));
    enqueue(queue, create_item(17));
    enqueue(queue, create_item(18));

    int error = enqueue(queue, create_item(19));

    assert(!error);
    assert(queue->length == 5);
    assert(queue->head != queue->tail);
    assert(queue->head->item->value == 15);
    assert(queue->head->next->item->value == 16);
    assert(queue->head->next->next->item->value == 17);
    assert(queue->head->next->next->next->item->value == 18);
    assert(queue->head->next->next->next->next->item->value == 19);
    assert(queue->tail->item->value == 19);

    printf("✅ PASS: %s\n", __func__);
}


void test_cannot_enqueue_on_full_empty_queue() {
    queue_t *queue = create_queue(4);

    enqueue(queue, create_item(15));
    enqueue(queue, create_item(16));
    enqueue(queue, create_item(17));
    enqueue(queue, create_item(18));

    int error = enqueue(queue, create_item(19));

    assert(error);
    assert(queue->length == queue->size);
    assert(queue->head->item->value == 15);
    assert(queue->tail->item->value == 18);
}


void test_can_dequeue_on_empty_queue() {
    queue_t *queue = create_queue(0);

    item_t *dequeued = dequeue(queue);

    assert(dequeued == NULL);
    assert_empty_queue(*queue);

    printf("✅ PASS: %s\n", __func__);
}


void test_can_dequeue_on_non_empty_queue() {
    queue_t *queue = create_queue(0);

    enqueue(queue, create_item(15));
    enqueue(queue, create_item(16));
    enqueue(queue, create_item(17));
    enqueue(queue, create_item(18));

    item_t *dequeued = dequeue(queue);

    assert(dequeued != NULL);
    assert(dequeued->value == 15);
    assert(queue->length == 3);
    assert(queue->head->item->value == 16);

    printf("✅ PASS: %s\n", __func__);
}


void test_can_peek_at_head_on_empty_queue() {
    queue_t *queue = create_queue(0);

    item_t *peeked = peek_head(queue);

    assert(peeked == NULL);
    assert_empty_queue(*queue);

    printf("✅ PASS: %s\n", __func__);
}


void test_can_peek_at_head_on_non_empty_queue() {
    queue_t *queue = create_queue(0);

    enqueue(queue, create_item(15));
    enqueue(queue, create_item(16));
    enqueue(queue, create_item(17));
    enqueue(queue, create_item(18));

    item_t *peeked = peek_head(queue);

    assert(peeked != NULL);
    assert(peeked->value == 15);
    assert(queue->length == 4);
    assert(queue->head->item->value == 15);

    printf("✅ PASS: %s\n", __func__);
}


void test_can_peek_at_tail_on_empty_queue() {
    queue_t *queue = create_queue(0);

    item_t *peeked = peek_tail(queue);

    assert(peeked == NULL);
    assert_empty_queue(*queue);

    printf("✅ PASS: %s\n", __func__);
}


void test_can_peek_at_tail_on_non_empty_queue() {
    queue_t *queue = create_queue(0);

    enqueue(queue, create_item(15));
    enqueue(queue, create_item(16));
    enqueue(queue, create_item(17));
    enqueue(queue, create_item(18));

    item_t *peeked = peek_tail(queue);

    assert(peeked != NULL);
    assert(peeked->value == 18);
    assert(queue->length == 4);
    assert(queue->tail->item->value == 18);

    printf("✅ PASS: %s\n", __func__);
}


void test_can_clear_empty_queue() {
    queue_t *queue = create_queue(0);

    clear(queue);

    assert_empty_queue(*queue);

    printf("✅ PASS: %s\n", __func__);
}


void test_can_clear_non_empty_queue() {
    queue_t *queue = create_queue(0);

    enqueue(queue, create_item(15));
    enqueue(queue, create_item(16));
    enqueue(queue, create_item(17));
    enqueue(queue, create_item(18));

    clear(queue);

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