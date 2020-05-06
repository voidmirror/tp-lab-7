//
// Created by artem on 05.04.2020.
//

#include "Cell.h"

Cell::Cell() {

}

void Cell::setOcean(Ocean *ocean) {
    this->ocean = ocean;
}

void Cell::setObject(Object *object) {
    this->object = object;
}

char Cell::getView() {
    if (object == nullptr) {
        return '.';
    } else {
        return object->getView();
    }
}

Ocean *Cell::getOcean() {
    return ocean;
}

Object *Cell::getObject() const {
    return object;
}
