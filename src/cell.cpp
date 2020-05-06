
#include "cell.h"

void Cell::init(Pair p, Ocean *oc)
{
	this->crd = p;
	this->ocean = oc;
}

Object* Cell::getObject() const
{
	return obj;
}

void Cell::setObject(Object* object)
{
	this->obj = object;
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
