//
// Created by aklen on 23.04.2020.
//
#include "Cell.h"


void Cell::setObject(Object *object) {
    obj = object;
}


void Cell::initObj(Pair p, Ocean *oc) {
    obj = nullptr;
    coord = p;
    ocean = oc;
}


Object* Cell::getObject() {
    return obj;
}


Ocean* Cell::getOcean() {
    return ocean;
}


void Cell::kill() {
    obj = nullptr;
}


Cell* Cell::search_empty() {
    return ocean->search_empty(coord);
}

Cell* Cell::search_prey() {
    return ocean->search_prey(coord);
}


