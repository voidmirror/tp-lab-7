#include "Cell.h"

void Cell::init(Pair p, Ocean *oc)
{
	crd = p;
	ocean = oc;
}

Object* Cell::getObject() const
{
	return obj;
}

void Cell::setObject(Object* object)
{
	obj = object;
}

Pair Cell::getCrd()
{
	return crd;
}

Ocean* Cell::getOcean()
{
	return ocean;
}

void Cell::killMe()
{
	if (obj != nullptr)
	{
		delete obj;
		obj = nullptr;
	}
}

Cell* Cell::findEmptyCellNear()
{
	return ocean->findEmptyCellNear(crd);
}

Cell* Cell::findFoodNear()
{
	return ocean->findFoodNear(crd);
}