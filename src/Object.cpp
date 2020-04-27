//
// Created by fiskirton on 08.04.2020.
//

#include "Object.h"
#include "Cell.h"
#include "Ocean.h"

void Object::setCell(Cell *cell) {
    Object::cell = cell;
}

Object::~Object() {
    cell->setObject(nullptr);
    setCell(nullptr);
}

char Object::getObjType() const {
    return obj_type;
}

Cell *Object::getCell() const {
    return cell;
}
