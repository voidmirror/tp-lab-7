#include "object.h"

Object::Object(Cell* c) : cell(c)
{
}

Cell* Object::getCell()
{
    return cell;
}

ObjType Object::getType()
{
    return type;
}

void Object::setLifetime(size_t lt)
{
    lifetime = lt;
}