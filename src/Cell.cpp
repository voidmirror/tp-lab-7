#include <iostream>
#include "Cell.h"

Cell::Cell() {
    object = nullptr;
}

Cell::Cell(Coordinates location) {
    this->location = location;
    object = nullptr;
}

bool Cell::isEmpty() {
    return object == nullptr;
}

void Cell::printView() {
    if (isEmpty()) {
        std::cout << character;
    } else {
        std::cout << object->getCharacter();
    }
}

Coordinates *Cell::getLocation() {
    return &location;
}

void Cell::setLocation(Coordinates location) {
    this->location = location;
}

Object *Cell::getObject() {
    return object;
}

void Cell::setObject(Object *object) {
    this->object = object;
}