#include "Object.h"
#include "Cell.h"

Object::Object(Cell* cell)
{
	setCell(cell);
}

void Object::setCell(Cell* cell)
{
	this->cell = cell;
}
