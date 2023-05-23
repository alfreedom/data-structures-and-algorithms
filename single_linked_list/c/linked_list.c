#include "item.h"
#include "linked_list.h"

#include <stdlib.h>

static linked_list_node_t* create_linked_list_node(item_t *item) {
    linked_list_node_t * node = (linked_list_node_t*) malloc(sizeof(linked_list_node_t));
    node->item = item;
    node->next = NULL;
    return node;
}

static void delete_linked_list_node(linked_list_node_t *node) {
    free(node);
    node = NULL;
}

linked_list_t* create_linked_list() {
    linked_list_t * list = (linked_list_t*) malloc(sizeof(linked_list_t));
    list->head = NULL;
    return list;
}

void clear_linked_list(linked_list_t *list) {
    linked_list_node_t *aux = list->head;
    while(aux) {
        aux = aux->next;
        delete_item(list->head->item);
        delete_linked_list_node(list->head);
        list->head = aux;
    }
    free(list);
    list = NULL;
}

int get_linked_list_length(linked_list_t *list) {
    int length = 0;
    linked_list_node_t *aux = list->head;

    while(aux) {
        length++;
        aux = aux->next;
    }

    return length;
}


void add_linked_list_item_at_head(linked_list_t * list, item_t *item) {
    linked_list_node_t *new_node = create_linked_list_node(item);
    new_node->next = list->head;
    list->head = new_node;
}


void add_linked_list_item_at_tail(linked_list_t *list, item_t *item) {
    linked_list_node_t *new_node = create_linked_list_node(item);
    if(!list->head) {
        list->head = new_node;
    } else {
        linked_list_node_t *aux = list->head;
        while(aux->next) {
            aux = aux->next;
        }
        aux->next = new_node;
    }
}


static void add_tail_recursive(linked_list_node_t **node, item_t *item) {
    if(!*node) {
        *node = create_linked_list_node(item);
    } else {
        add_tail_recursive(&(*node)->next, item);
    }
}

void add_linked_list_item_at_tail_recursive(linked_list_t *list, item_t *item) {
    add_tail_recursive(&(list->head), item);
}


item_t* remove_linked_list_item_at_head(linked_list_t *list) {
    if(!list->head) {
        return NULL;
    }

    linked_list_node_t *removed = list->head;
    list->head = removed->next;
    item_t *item = removed->item;
    delete_linked_list_node(removed);
    return item;
}


item_t* remove_linked_list_item_at_tail(linked_list_t *list) {
    linked_list_node_t *removed, *aux;

    // if empty list, return NULL
    if(!list->head) {
        return NULL;
    }

    // if only one item in list, set head to NULL
    if(!list->head->next) {
        removed = list->head;
        list->head = NULL;
    } else {
        // search for the previous node of the last node
        aux = list->head;
        while(aux->next->next) {
            aux = aux->next;
        }
        removed = aux->next;
        aux->next = NULL;
    }
    item_t *item = removed->item;
    delete_linked_list_node(removed);
    return item;
}


item_t* find_linked_list_item(linked_list_t *list, item_t *item) {
    linked_list_node_t *aux = list->head;

    while(aux) {
        if(items_are_equals(aux->item, item)) {
            return aux->item;
        }
        aux = aux->next;
    }
    return NULL;
}


static item_t* find_item_recursive(linked_list_node_t *node, item_t *item) {
    if(!node) {
        return NULL;
    }

    if(items_are_equals(node->item, item)) {
        return node->item;
    }

    return find_item_recursive(node->next, item);
}


item_t* find_linked_list_item_recursive(linked_list_t *list, item_t *item) {
    return find_item_recursive(list->head, item);
}


linked_list_node_t* get_linked_list_tail(linked_list_t *list) {

    if(!list->head) {
        return NULL;
    }

    linked_list_node_t *aux_node = list->head;
    while(aux_node->next) {
        aux_node = aux_node->next;
    }

    return aux_node;
}
