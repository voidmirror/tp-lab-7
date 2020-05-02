#include "Cell.h"

Cell::Cell(int x, int y) 
{
	this->x = x;
	this->y = y;
	this->object = nullptr;
}

int Cell::get_x()
{
	return this->x;
}

int Cell::get_y()
{
	return this->y;
}

void Cell::set_object(Object* object) 
{
	this->object = object;
}

Object* Cell::get_object() 
{
	return this->object;
}