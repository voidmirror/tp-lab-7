#include "Object.h"
#include<iostream>

Object::Object(Cell * cell)
{
	this->cell = cell;
};

void Object::setCell(Cell* cell)
{
	this->cell = cell;
};

Object* Object::getObject()
{
	return this;
}

char Object::getsymbol()
{
	std::cout << s;
	return s;
}

ObjType Object::getType()
{
	return type;
}

void Object::live()
{
	lifetime++;
}