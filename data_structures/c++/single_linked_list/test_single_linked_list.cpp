#include "item.h"
#include "linked_list.h"

#include <assert.h>
#include <iostream>

using namespace std;

LinkedList* create_sample_linked_list(int num_items) {
    LinkedList *list = new LinkedList();
    Item *item;
    for(int i=0; i < num_items; i++) {
        item = new Item(i+1);
        list->addHead(item);
    }
    return list;
}

void test_can_create_linked_list() {
    LinkedList *list = new LinkedList();

    assert(list->getHead() == NULL);
    printf("PASS: %s\n", __func__);
}

void test_can_add_linked_list_item_at_head_in_empty_list() {
    LinkedList *list = new LinkedList();
    Item *item = new Item(10);

    list->addHead(item);

    assert(list->getHead() != NULL);
    assert(list->getLength() == 1);
    assert(list->getHead()->getItem() == item);
    assert(list->getHead()->getItem()->getValue() == item->getValue());
    printf("PASS: %s\n", __func__);
}

void test_can_add_linked_list_item_at_head_in_non_empty_list() {
    int initial_list_lentgh = 5;
    LinkedList *list = create_sample_linked_list(5);
    Item *item = new Item(10);

    list->addHead(item);

    assert(list->getHead() != NULL);
    assert(list->getLength() == initial_list_lentgh + 1);
    assert(list->getHead()->getItem() == item);
    assert(list->getHead()->getItem()->getValue() == item->getValue());
    printf("PASS: %s\n", __func__);
}

void test_can_add_linked_list_item_at_tail_in_empty_list() {
    LinkedList *list = new LinkedList();
    Item *item = new Item(10);

    list->addTail(item);

    assert(list->getHead() != NULL);
    assert(list->getLength() == 1);
    assert(list->getHead()->getItem() == item);
    assert(list->getHead()->getItem()->getValue() == item->getValue());
    printf("PASS: %s\n", __func__);
}

void test_can_add_linked_list_item_at_tail_in_non_empty_list() {
    int initial_list_lentgh = 5;
    LinkedList *list = create_sample_linked_list(initial_list_lentgh);
    Item *item = new Item(10);

    list->addTail(item);

    assert(list->getHead() != NULL);
    assert(list->getLength() == initial_list_lentgh + 1);
    assert(list->getHead()->getItem()->getValue() == 5);
    printf("PASS: %s\n", __func__);
}

void test_can_add_linked_list_item_at_tail_in_empty_list_recursively() {
    LinkedList *list = new LinkedList();
    Item *item = new Item(10);

    list->addTailRecursive(item);

    assert(list->getHead() != NULL);
    assert(list->getLength() == 1);
    assert(list->getHead()->getItem() == item);
    assert(list->getHead()->getItem()->getValue() == item->getValue());
    printf("PASS: %s\n", __func__);
}

void test_can_add_linked_list_item_at_tail_in_non_empty_list_recursively() {
    int initial_list_lentgh = 5;
    LinkedList *list = create_sample_linked_list(initial_list_lentgh);
    Item *item = new Item(10);

    list->addTailRecursive(item);

    assert(list->getHead() != NULL);
    assert(list->getLength() == initial_list_lentgh + 1);
    assert(list->getHead()->getItem()->getValue() == 5);
    printf("PASS: %s\n", __func__);
}

void test_can_remove_linked_list_item_at_head_in_empty_list() {
    LinkedList *list = new LinkedList();

    Item *removed = list->removeHead();

    assert(removed == NULL);
    assert(list->getLength() == 0);
    printf("PASS: %s\n", __func__);
}

void test_can_remove_linked_list_item_at_head_in_non_empty_list() {
    int initial_list_lentgh = 5;
    LinkedList *list = create_sample_linked_list(initial_list_lentgh);

    Item *removed = list->removeHead();

    assert(removed != NULL);
    assert(removed->getValue() == 5);
    assert(list->getLength() == initial_list_lentgh - 1);
    printf("PASS: %s\n", __func__);
}

void test_can_remove_linked_list_item_at_tail_in_empty_list() {
    LinkedList *list = new LinkedList();

    Item *removed = list->removeTail();

    assert(removed == NULL);
    assert(list->getLength() == 0);
    printf("PASS: %s\n", __func__);
    printf("PASS: %s\n", __func__);
}

void test_can_remove_linked_list_item_at_tail_in_non_empty_list() {
    int initial_list_lentgh = 5;
    LinkedList *list = create_sample_linked_list(initial_list_lentgh);

    Item *removed = list->removeTail();

    assert(removed != NULL);
    assert(removed->getValue() == 1);
    assert(list->getLength() == initial_list_lentgh - 1);
    printf("PASS: %s\n", __func__);
}

void test_can_remove_linked_list_item_at_tail_in_non_empty_list_with_one_element() {
    int initial_list_lentgh = 1;
    LinkedList *list = create_sample_linked_list(initial_list_lentgh);

    Item *removed = list->removeTail();

    assert(removed != NULL);
    assert(list->getHead() == NULL);
    assert(removed->getValue() == 1);
    assert(list->getLength() == initial_list_lentgh - 1);
    printf("PASS: %s\n", __func__);
}

void test_can_find_linked_list_item_in_empty_list() {
    LinkedList *list = new LinkedList();
    Item *item_to_find = new Item(100);

    Item *item_found = list->findItem(item_to_find);

    assert(item_found == NULL);
    printf("PASS: %s\n", __func__);
}

void test_can_find_linked_list_item_in_non_empty_list() {
    LinkedList *list = create_sample_linked_list(5);
    Item *item_to_find = new Item(3);

    Item *item_found = list->findItem(item_to_find);

    assert(item_found != NULL);
    assert(item_found->getValue() == 3);
    printf("PASS: %s\n", __func__);
}

void test_can_find_non_existent_linked_list_item_in_non_empty_list() {
    LinkedList *list = create_sample_linked_list(5);
    Item *item_to_find = new Item(100);

    Item *item_found = list->findItem(item_to_find);

    assert(item_found == NULL);
    printf("PASS: %s\n", __func__);
}

void test_can_find_linked_list_item_in_empty_list_recursively() {
    LinkedList *list = new LinkedList();
    Item *item_to_find = new Item(100);

    Item *item_found = list->findItemRecursive(item_to_find);

    assert(item_found == NULL);
    printf("PASS: %s\n", __func__);
}

void test_can_find_linked_list_item_in_non_empty_list_recursively() {
    LinkedList *list = create_sample_linked_list(5);
    Item *item_to_find = new Item(3);

    Item *item_found = list->findItemRecursive(item_to_find);

    assert(item_found != NULL);
    assert(item_found->getValue() == 3);
    printf("PASS: %s\n", __func__);
}

void test_can_find_non_existent_linked_list_item_in_non_empty_list_recursively() {
    LinkedList *list = create_sample_linked_list(5);
    Item *item_to_find = new Item(100);

    Item *item_found = list->findItemRecursive(item_to_find);

    assert(item_found == NULL);
    printf("PASS: %s\n", __func__);
}

int main(int argc, char* argv[]) {

    test_can_create_linked_list();
    test_can_add_linked_list_item_at_head_in_empty_list();
    test_can_add_linked_list_item_at_head_in_non_empty_list();
    test_can_add_linked_list_item_at_tail_in_empty_list();
    test_can_add_linked_list_item_at_tail_in_non_empty_list();
    test_can_add_linked_list_item_at_tail_in_empty_list_recursively();
    test_can_add_linked_list_item_at_tail_in_non_empty_list_recursively();
    test_can_remove_linked_list_item_at_head_in_empty_list();
    test_can_remove_linked_list_item_at_head_in_non_empty_list();
    test_can_remove_linked_list_item_at_tail_in_empty_list();
    test_can_remove_linked_list_item_at_tail_in_non_empty_list();
    test_can_remove_linked_list_item_at_tail_in_non_empty_list_with_one_element();
    test_can_find_linked_list_item_in_empty_list();
    test_can_find_linked_list_item_in_non_empty_list();
    test_can_find_non_existent_linked_list_item_in_non_empty_list();
    test_can_find_linked_list_item_in_empty_list_recursively();
    test_can_find_linked_list_item_in_non_empty_list_recursively();
    test_can_find_non_existent_linked_list_item_in_non_empty_list_recursively();
}