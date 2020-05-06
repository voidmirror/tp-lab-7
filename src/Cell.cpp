#include "Common.h"
#include "Ocean.h"
#include "Cell.h"

void Cell::init(Pair p, Ocean* oc)
{
	crd = p;
	ocean = oc;
	obj = nullptr;
}

Object* Cell::getObject()
{
	return obj;
}

void Cell::setObject(Object *obj)
{
	this->obj = obj;
}

void Cell::killMe()
{
	obj = nullptr;
}