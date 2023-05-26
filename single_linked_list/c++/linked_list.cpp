#include "linked_list.h"

#include <iostream>

using namespace std;


// Node methods
Node::Node(Item *item) {
    this->item = item;
    this->next = NULL;
}

Node::~Node() {}

Item* Node::getItem() {
    return this->item;
}

void  Node::setItem(Item* item) {
    this->item = item;
}


// Linked list methods
LinkedList::LinkedList(){
    this->head = NULL;
}


LinkedList::~LinkedList() {}

void LinkedList::print() {
    Node *aux = this->head;
    cout << "[";
    while(aux) {
        cout << aux->getItem()->getValue();
        if(aux->next) {
            cout << ", ";
        }
        aux = aux->next;
    }
    cout << "]";

}

Node* LinkedList::getHead() {
    return this->head;
}


int LinkedList::getLength() {
    Node * aux = this->head;
    int length = 0;
    while(aux) {
        length++;
        aux = aux->next;
    }
    return length;
}


void LinkedList::addHead(Item *item) {
    Node *new_node = new Node(item);
    new_node->next = this->head;
    this->head = new_node;
}

void LinkedList::addTail(Item *item) {
    Node *aux_node = this->head;

    if(!aux_node) {
        this->addHead(item);
    } else {
        while(aux_node->next) {
            aux_node = aux_node->next;
        }
        aux_node->next = new Node(item);
    }
}

static void add_tail_recursive(Node **node, Item *item) {
    if(!*node) {
        *node = new Node(item);
        return;
    }
    add_tail_recursive(&(*node)->next, item);
}

void LinkedList::addTailRecursive(Item *item) {
    add_tail_recursive(&this->head, item);
}

Item* LinkedList::removeHead() {
    if(!this->head) {
        return NULL;
    }

    Node *removed = this->head;
    this->head = removed->next;
    Item* item = removed->getItem();
    delete removed;
    return item;
}

Item* LinkedList::removeTail() {
    if(!this->head) {
        return NULL;
    }

    if(!this->head->next) {
        return this->removeHead();
    }

    Node *aux = this->head;
    while(aux->next->next) {
        aux = aux->next;
    }

    Node *removed = aux->next;
    Item *item = removed->getItem();
    aux->next = NULL;
    delete removed;

    return item;
}

Item* LinkedList::findItem(Item *item) {
    Node *aux = this->head;
    while(aux) {
        if(aux->getItem()->getValue() == item->getValue()) {
            return aux->getItem();
        }
        aux = aux->next;
    }
    return NULL;
}


static Item* find_item_recursive(Node *node, Item *item) {
    if(!node) {
        return NULL;
    }
    if(node->getItem()->getValue() == item->getValue()) {
        return node->getItem();
    }
    return find_item_recursive(node->next, item);
}

Item* LinkedList::findItemRecursive(Item *item) {
    return find_item_recursive(this->head, item);
}