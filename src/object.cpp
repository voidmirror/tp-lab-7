#include "object.h"

Object::Object(Cell *newCell) {
    cell = newCell;
    typeOfObject = ObjType::NONE;
}

ObjType Object::getObjType() {
    return typeOfObject;
}

Cell *Object::getCell() {
    return cell;
}

void Object::setCell(Cell *newCell) {
    cell = newCell;
}