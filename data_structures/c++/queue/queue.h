#ifndef QUEUE_H_
#define QUEUE_H_

#include "item.h"


class Node {
private:
    Item *item;
    Node *next;

public:
    Node(Item *item);
    virtual ~Node();

    Node* getNext();
    void setNext(Node* node);
    Item* getItem();
};


class Queue {

private:
    Node *head;
    Node *tail;
    int length;
    int size;

public:
    Queue(int size = 0);
    virtual ~Queue();

    int enqueue(Item *item);
    Item* dequeue();
    Item* peek_head();
    Item* peek_tail();
    void clear();

    int getLength();
    int getSize();
    Node* getHead();
    Node* getTail();
};

#endif // QUEUE_H_
