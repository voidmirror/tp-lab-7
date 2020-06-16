#include "Object.h"
#include<iostream>

Object::Object(Cell* cell)
{
	this->cell = cell;
}

void Object::setCell(Cell* cell)
{
	this->cell = cell;
}

Object* Object::getObject()
{
	return this;
}

Cell* Object::getCell()
{
	return cell;

}

char Object::getsymbol()
{
	return s;
}



ObjectType Object::gettype()
{
	return type;
}

void Object::setLifetime(int lt)
{
	lifetime = lt;
}
