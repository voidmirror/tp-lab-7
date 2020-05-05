#include "Object.h"

Object::Object(Cell *c) : cell(c)
{
}

Cell* Object::getCell()
{
    return cell;
}

Type Object::getType()
{
    return type;
}

void Object::setLifetime(size_t lt)
{
    lifetime = lt;
}

std::string Object::getSymbol()
{
    return this->symbol;
}
