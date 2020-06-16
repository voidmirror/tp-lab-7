#include "Common.h"
#include "Ocean.h"
#include "Cell.h"



void Cell::init(Pair pair, Ocean* ocean)
{
	this->crd = pair;
	this->ocean = ocean;
	object = nullptr;
}

Object* Cell::getObject()
{
	return object;
}

void Cell::setObject(Object* object)
{
	this->object = object;
}

void Cell::killMe()
{
	if (object)
	{
		delete object;
		object = nullptr;
	}
}

Ocean* Cell::getOcean()
{
	return ocean;
}

Cell* Cell::findEmpty()
{
	return ocean->Empty(crd);
}

Cell* Cell::findPrey()
{
	return ocean->Prey1(crd);
}