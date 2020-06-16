#include "Object.h"

Object::Object(Cell* cell, ObjType type)
{
	this->cell = cell;
	this->type = type;
}

ObjType Object::getType()
{
	return this->type;
}

Cell* Object::getCell()
{
	return this->cell;
}

void Object::setCell(Cell* cell)
{
	this->cell = cell;
}

void Object::setLifespan(int timeOut)
{
	this->lifespan = timeOut;
}