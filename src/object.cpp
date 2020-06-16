//
// Created by Ignatovskiy Nikita on 28.04.2020.
//


#include "object.h"


Object::Object(Cell *c) : cell(c)
{

}


ObjType Object::getType()
{
    return this->type;
}


Cell* Object::getCell()
{
    return this->cell;
}


void Object::setLifeTime(int lifetimeValue)
{
    this->lifetime = lifetimeValue;
}


