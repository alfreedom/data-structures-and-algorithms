#include "item.h"

#include <stdlib.h>


item_t* create_item(int value) {
    item_t *new_item = (item_t*) malloc(sizeof(item_t));
    new_item->value = value;
    return new_item;
}

void delete_item(item_t* item) {
    free(item);
    item = NULL;
}

int items_are_equals(item_t *item1, item_t *item2){
    return item1->value == item2->value;
}