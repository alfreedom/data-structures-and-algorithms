#include "item.h"
#include "linked_list.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


linked_list_t* create_sample_linked_list(int num_items) {
    linked_list_t * list = create_linked_list();
    item_t *item;
    for(int i=0; i < num_items; i++) {
        item = create_item(i+1);
        add_linked_list_item_at_head(list, item);
    }
    return list;
}

void test_can_create_linked_list() {
    linked_list_t *list = create_linked_list();

    assert(list != NULL);
    assert(list->head == NULL);
    assert(get_linked_list_length(list) == 0);

    clear_linked_list(list);
    printf("PASS: %s\n", __func__);
}

void test_can_add_linked_list_item_at_head_in_empty_list() {
    linked_list_t *list = create_linked_list();
    item_t *item = create_item(10);

    add_linked_list_item_at_head(list, item);

    assert(list->head != NULL);
    assert(get_linked_list_length(list) == 1);
    assert(list->head->item->value == item->value);

    clear_linked_list(list);
    printf("PASS: %s\n", __func__);
}

void test_can_add_linked_list_item_at_head_in_non_empty_list() {
    int list_item_count = 5;
    linked_list_t *list = create_sample_linked_list(list_item_count);
    item_t *item = create_item(100);

    add_linked_list_item_at_head(list, item);

    assert(list->head->item->value == item->value);
    assert(get_linked_list_length(list) == list_item_count + 1);

    clear_linked_list(list);
    printf("PASS: %s\n", __func__);
}

void test_can_add_linked_list_item_at_tail_in_empty_list() {
    linked_list_t *list = create_linked_list();
    item_t *item = create_item(10);

    add_linked_list_item_at_tail(list, item);

    assert(list->head != NULL);
    assert(get_linked_list_length(list) == 1);
    assert(list->head->item->value == item->value);

    clear_linked_list(list);
    printf("PASS: %s\n", __func__);
}

void test_can_add_linked_list_item_at_tail_in_non_empty_list() {
    int list_item_count = 5;
    linked_list_t *list = create_sample_linked_list(list_item_count);
    item_t *item = create_item(100);

    add_linked_list_item_at_tail(list, item);

    linked_list_node_t *list_tail = get_linked_list_tail(list);

    assert(get_linked_list_length(list) == list_item_count + 1);
    assert(list_tail->item == item);
    assert(list_tail->item->value == item->value);

    clear_linked_list(list);
    printf("PASS: %s\n", __func__);
}

void test_can_add_linked_list_item_at_tail_in_empty_list_recursively() {
    linked_list_t *list = create_linked_list();
    item_t *item = create_item(10);

    add_linked_list_item_at_tail_recursive(list, item);

    assert(list->head != NULL);
    assert(get_linked_list_length(list) == 1);
    assert(list->head->item->value == item->value);

    clear_linked_list(list);
    printf("PASS: %s\n", __func__);
}

void test_can_add_linked_list_item_at_tail_in_non_empty_list_recursively() {
    int list_item_count = 5;
    linked_list_t *list = create_sample_linked_list(list_item_count);
    item_t *item = create_item(100);

    add_linked_list_item_at_tail_recursive(list, item);

    linked_list_node_t *list_tail = get_linked_list_tail(list);

    assert(get_linked_list_length(list) == list_item_count + 1);
    assert(list_tail->item == item);
    assert(list_tail->item->value == item->value);

    clear_linked_list(list);
    printf("PASS: %s\n", __func__);
}

void test_can_remove_linked_list_item_at_head_in_empty_list() {
    linked_list_t *list = create_linked_list();

    item_t *item = remove_linked_list_item_at_head(list);

    assert(item == NULL);

    free(item);
    clear_linked_list(list);
    printf("PASS: %s\n", __func__);
}

void test_can_remove_linked_list_item_at_head_in_non_empty_list() {
    int list_item_count = 5;
    linked_list_t *list = create_sample_linked_list(list_item_count);

    item_t *item = remove_linked_list_item_at_head(list);

    assert(item != NULL);
    assert(get_linked_list_length(list) == list_item_count - 1);
    assert(item->value == 5);

    free(item);
    clear_linked_list(list);
    printf("PASS: %s\n", __func__);
}

void test_can_remove_linked_list_item_at_tail_in_empty_list() {
    linked_list_t *list = create_linked_list();

    item_t *item = remove_linked_list_item_at_tail(list);

    assert(item == NULL);

    free(item);
    clear_linked_list(list);
    printf("PASS: %s\n", __func__);
}

void test_can_remove_linked_list_item_at_tail_in_non_empty_list() {
    int list_item_count = 5;
    linked_list_t *list = create_sample_linked_list(list_item_count);

    item_t *item = remove_linked_list_item_at_tail(list);

    assert(item != NULL);
    assert(get_linked_list_length(list) == list_item_count - 1);
    assert(item->value == 1);

    free(item);
    clear_linked_list(list);
    printf("PASS: %s\n", __func__);
}

void test_can_remove_linked_list_item_at_tail_in_non_empty_list_with_one_element() {
    int list_item_count = 1;
    linked_list_t *list = create_sample_linked_list(list_item_count);

    item_t *item = remove_linked_list_item_at_tail(list);

    assert(item != NULL);
    assert(list->head == NULL);
    assert(get_linked_list_length(list) == list_item_count - 1);
    assert(item->value == 1);

    free(item);
    clear_linked_list(list);
    printf("PASS: %s\n", __func__);
}


void test_can_find_linked_list_item_in_empty_list() {
    linked_list_t *list = create_linked_list();
    item_t item_to_find = {.value = 3};

    item_t *item_found = find_linked_list_item(list, &item_to_find);

    assert(item_found == NULL);

    clear_linked_list(list);
    printf("PASS: %s\n", __func__);
}

void test_can_find_linked_list_item_in_non_empty_list() {
    int list_item_count = 5;
    linked_list_t *list = create_sample_linked_list(list_item_count);

    item_t item_to_find = {.value = 3};

    item_t *item_found = find_linked_list_item(list, &item_to_find);

    assert(item_found != NULL);
    assert(item_found->value == 3);

    clear_linked_list(list);
    printf("PASS: %s\n", __func__);
}

void test_can_find_non_existent_linked_list_item_in_non_empty_list() {
    int list_item_count = 5;
    linked_list_t *list = create_sample_linked_list(list_item_count);

    item_t item_to_find = {.value = 15};

    item_t *item_found = find_linked_list_item(list, &item_to_find);

    assert(item_found == NULL);

    clear_linked_list(list);
    printf("PASS: %s\n", __func__);

}

void test_can_find_linked_list_item_in_empty_list_recursively() {
    linked_list_t *list = create_linked_list();
    item_t item_to_find = {.value = 3};

    item_t *item_found = find_linked_list_item_recursive(list, &item_to_find);

    assert(item_found == NULL);

    clear_linked_list(list);
    printf("PASS: %s\n", __func__);
}

void test_can_find_linked_list_item_in_non_empty_list_recursively() {
    int list_item_count = 5;
    linked_list_t *list = create_sample_linked_list(list_item_count);

    item_t item_to_find = {.value = 3};

    item_t *item_found = find_linked_list_item_recursive(list, &item_to_find);

    assert(item_found != NULL);
    assert(item_found->value == 3);

    clear_linked_list(list);
    printf("PASS: %s\n", __func__);
}

void test_can_find_non_existent_linked_list_item_in_non_empty_list_recursively() {
    int list_item_count = 5;
    linked_list_t *list = create_sample_linked_list(list_item_count);

    item_t item_to_find = {.value = 15};

    item_t *item_found = find_linked_list_item_recursive(list, &item_to_find);

    assert(item_found == NULL);

    clear_linked_list(list);
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