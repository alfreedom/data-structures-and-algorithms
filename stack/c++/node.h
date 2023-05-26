#ifndef NODE_H_
#define NODE_H_

#include "item.h"

class Node {
    private:
        Item *item;
        Node *next;

    public:
        Node(Item* item);
        virtual ~Node();

        Item* getItem();
        void setItem(Item *item);

        Node* getNext();
        void setNext(Node *node);
};

#endif /* NODE_H_ */