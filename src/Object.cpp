//
// Created by aklen on 23.04.2020.
//
#include "Object.h"


Object::Object(Cell *cell) {
    this->cell = cell;
}


void Object::setCell(Cell *cell) {
    this->cell = cell;
}


Cell* Object::getCell() {
    return cell;
}


ObjType Object::getType() {
    return type;
}


void Object::set_lifetime(int lifetime) {
    this->lifetime = lifetime;
}