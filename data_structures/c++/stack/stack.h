#ifndef STACK_H_
#define STACK_H_

#include "node.h"
#include "item.h"


class Stack {
    private:
        Node *top;
        int size;
        int length;

    public:
        Stack(int size = 0);
        virtual ~Stack();

        int push(Item *item);
        Item* pop();
        Item* peek();

        int getSize();
        int getLength();
        Node* getTop();
};


#endif /* STACK_H_*/