//
// Created by iddoroshenko on 26.03.2020.
//

#include "Cell.h"
void Cell::init(Pair p, Ocean *oc) {
    crd = p;
    ocean = oc;
}

Object* Cell::getObject() const{
    return obj;
}

void Cell::setObject(Object* _obj) {
    obj = _obj;
}

void Cell::killMe() {
    obj = nullptr;
}

Pair Cell::getCrd() const {
    return crd;
}

Ocean *Cell::getOcean() {
    return ocean;
}
