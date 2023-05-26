
#include "node.h"

#include <iostream>


Node::Node(Item* item) {
    this->item = item;
    this->next = NULL;
}

Node::~Node() {}

Item* Node::getItem() {
    return this->item;
}

void Node::setItem(Item *item) {
    this->item = item;
}

Node* Node::getNext() {
    return this->next;
}

void Node::setNext(Node *node){
    this->next = node;
}