#include "Object.h"

Object::Object(Cell* c)
{
	cell = c;
	life = 0;
	alive = true;
}

void Object::setCell(Cell * c)
{
	cell = c;
}

ObjType Object::getSpecies()
{
	return species;
}

bool Object::isAlive()
{
	return alive;
}

Cell* Object::getCell()
{
	return cell;
}

char Object::getSymb()
{
	return symb;
}