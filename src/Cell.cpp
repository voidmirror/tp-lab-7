#include "Cell.h"

Cell::Cell()
{
	this->crd.x = NULL;
	this->crd.y = NULL;
	this->ocean = NULL;
	this->object = NULL;
}

Cell::Cell(int x, int y, Ocean* ocean)
{
	this->crd.x = x;
	this->crd.y = y;
	this->ocean = ocean;
	this->object = NULL;
}

void Cell::setObject(Object* object)
{
	this->object = object;
}

Pair Cell::getPair()
{
	return this->crd;
}

Cell* Cell::findEmptyCell()
{
	return this->getOcean()->findEmpty(this);
}

Cell* Cell::findPreyCell()
{
	return this->getOcean()->findPrey(this);
}

Ocean* Cell::getOcean()
{
	return this->ocean;
}

Object* Cell::getObject()
{
	return this->object;
}

void Cell::killMe()
{
	delete this->object;
	this->object = NULL;
}