#include "Object.h"

Object::Object(Cell* cell)
{
	this->cell = cell;
	this->type = Object_type::empty_space;
}

void Object::set_cell(Cell* cell)
{
	this->cell = cell;
}

Cell* Object::get_cell()
{
	return this->cell;
}

Object_type Object::get_type()
{
	return this->type;
}
