
#include "stack.h"

#include <iostream>

using namespace std;


Stack::Stack(int size) {
    this->top = NULL;
    this->size = size;
    this->length = 0;
}

Stack::~Stack() {}

int Stack::push(Item *item) {
    if(this->size == 0 || this->length < this->size) {
        Node *new_node = new Node(item);
        new_node->setNext(this->top);
        this->top = new_node;
        this->length++;
        return 1;
    }
    return 0;
}


Item* Stack::pop() {
    Item *item = NULL;
    if(this->top) {
        Node *removed = this->top;
        this->top = removed->getNext();
        item = removed->getItem();
        this->length--;
        delete(removed);
    }

    return item;
}


Item* Stack::peek() {
    if(this->top) {
        return this->top->getItem();
    }
    return NULL;
}


int Stack::getSize() {
    return this->size;
}


int Stack::getLength() {
    return this->length;
}


Node* Stack::getTop() {
    return this->top;
}