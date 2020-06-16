#include "Object.h"

Object::Object(Cell* cell = nullptr)
{
    this->cell = cell;
    this->alive = true;
}

Object::~Object()
{
}

void Object::setCell(Cell* cell)
{
    this->cell = cell;
}

Cell* Object::getCell() const
{
    return this->cell;
}

void Object::die()
{
    this->alive = false;
}

bool Object::isAlive()
{
    return this->alive;
}