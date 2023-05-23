#ifndef LIST_H_
#define LIST_H_

#include "item.h"

// Structure to represent a linked list node
typedef struct node {
    item_t *item;
    struct node *next;
} linked_list_node_t;

// Structure to represent a linked list
typedef struct linked_list {
    linked_list_node_t *head;
} linked_list_t;


// Prototype functions
static linked_list_node_t* create_linked_list_node();
static void delete_linked_list_node(linked_list_node_t *node);
linked_list_t* create_linked_list();
void clear_linked_list(linked_list_t *list);

linked_list_node_t* get_linked_list_tail(linked_list_t *list);
int get_linked_list_length(linked_list_t *list);
void add_linked_list_item_at_head(linked_list_t *list, item_t *item);
void add_linked_list_item_at_tail(linked_list_t *list, item_t *item);
void add_linked_list_item_at_tail_recursive(linked_list_t *list, item_t *item);
item_t* remove_linked_list_item_at_head(linked_list_t *list);
item_t* remove_linked_list_item_at_tail(linked_list_t *list);
item_t* find_linked_list_item(linked_list_t *list, item_t *item);
item_t* find_linked_list_item_recursive(linked_list_t *list, item_t *item);

#endif /* LIST_H_*/