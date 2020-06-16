//
// Created by Mary on 15.04.2020.
//
#include "object.h"
Object::Object(Cell *c) : cell(c) {
    typeOfObject = ObjType :: NONE;
}
ObjType Object::getTypeOfObject()
{
    return typeOfObject;
}
void Object::setCell(Cell* newCell)
{
    cell = newCell;
}
Cell* Object::getCell()
{
    return cell;
}
