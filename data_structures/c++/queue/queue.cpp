#include "queue.h"
#include "item.h"

#include <stdlib.h>


// Node methods implementation
Node::Node(Item *item) {
    this->item  = item;
    this->next = NULL;
}

Node::~Node() {}


Node* Node::getNext() {
    return this->next;
}

void Node::setNext(Node * node) {
    this->next = node;
}

Item* Node::getItem() {
    return this->item;
}
// Ends NODE



// Queue methods implementation
Queue::Queue(int size) {
    this->size = size;
    this->length = 0;
    this->head = NULL;
    this->tail = NULL;
}

Queue::~Queue() {}

int Queue::enqueue(Item *item) {
    if (this->size == 0 || this->length < this->size) {
        Node *new_node = new Node(item);

        if(!this->tail) {
            this->head = new_node;
        } else {
            this->tail->setNext(new_node);
        }

        this->tail = new_node;
        this->length++;
        return 0;
    }
    return 1;
}

Item* Queue::dequeue() {
    if(!this->head) {
        return NULL;
    }

    if(this->tail == this->head) {
        this->tail = NULL;
    }

    Node *removed = this->head;
    Item * item = this->head->getItem();
    this->head = this->head->getNext();
    this->length--;
    delete removed ;

    return item;
}

Item* Queue::peek_head() {
    if(this->head) {
        return this->head->getItem();
    }
    return NULL;
}

Item* Queue::peek_tail() {
    if(this->tail) {
        return this->tail->getItem();
    }
    return NULL;
}

void Queue::clear() {
    while(this->head) {
        Item *item = this->dequeue();
        if(item) {
            delete item ;
        }
    }
}

int Queue::getLength() {
    return this->length;
}

int Queue::getSize() {
    return this->size;
}

Node* Queue::getHead() {
    return this->head;
}

Node* Queue::getTail() {
    return this->tail;
}

// End Queue