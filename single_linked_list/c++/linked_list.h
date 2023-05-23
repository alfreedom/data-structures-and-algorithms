#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "item.h"

class Node {
    private:
    Item *item;

    public:
    Node* next;
    Node(Item *item);
    virtual ~Node();

    Item* getItem();
    void setItem(Item* item);
};

class LinkedList{
    private:
    Node *head;

    public:
    LinkedList();
    virtual ~LinkedList();
    void print();

    Node* getHead();
    int getLength();

    void addHead(Item *item);
    void addTail(Item *item);
    void addTailRecursive(Item *item);

    Item* removeHead();
    Item* removeTail();
    Item* findItem(Item *item);
    Item* findItemRecursive(Item *item);
};

#endif /* LINKED_LIST_H_ */