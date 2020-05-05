//
// Created by Mikhail on 05.05.2020.
//

#include <object.h>
#include <cell.h>

Object::Object(Cell *_cell) {
    cell = _cell;
}

void Object::setCell(Cell *_cell) {
    cell = _cell;
}

bool Object::live() {
    return false;
}

ObjType Object::getType() {
    return type;
}

Cell *Object::getCell() {
    return cell;
}
