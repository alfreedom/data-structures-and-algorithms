
#include "item.h"

Item::Item(int value) {
    this->value = value;
}

Item::~Item() {

}

int Item::getValue() {
    return this->value;
}

void Item::setValue(int value) {
    this->value = value;
}

bool Item::operator==(const Item &other) {
    return this->value == other.value;
}
