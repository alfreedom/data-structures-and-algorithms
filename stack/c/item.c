#include "item.h"

#include <stdlib.h>


item_t* create_item(int value) {
    item_t * item = (item_t *) malloc(sizeof(item_t));
    item->value = value;
    return item;
}
