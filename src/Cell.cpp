#include <iostream>
#include "Cell.h"

Cell::Cell() {
    object = nullptr;
}

Cell::Cell(coord location) {
    this->location = location;
    object = nullptr;
}

void Cell::setObject(Object *object) {
    this->object = object;
}

Object *Cell::getObject() {
    return object;
}

bool Cell::isEmpty() {
    return object == nullptr;
}

void Cell::printSymbol() {
    if (isEmpty()) {
        std::cout << symbol;
    } else {
        std::cout << object->getSymbol();
    }
}

char Cell::getSymbol() {
    if (isEmpty()) {
        return symbol;
    } else {
        return object->getSymbol();
    }
}

coord *Cell::getLocation() {
    return &location;
}

void Cell::setLocation(coord location) {
    this->location = location;
}