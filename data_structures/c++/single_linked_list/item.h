#ifndef ITEM_H_
#define ITEM_H_


class Item {

private:
    int value;

public:
    Item(int value);
    virtual ~Item();

    int getValue();
    void setValue(int value);

    bool operator == (const Item &other);
};

#endif /* ITEM_H_*/