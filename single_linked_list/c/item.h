#ifndef ITEM_H_
#define ITEM_H_

// Item data structure
typedef struct item {
    int value;
} item_t;

// Prototype functions
item_t* create_item(int value);
void delete_item(item_t* item);
int items_are_equals(item_t *item1, item_t *item2);

#endif /* ITEM_H_ */