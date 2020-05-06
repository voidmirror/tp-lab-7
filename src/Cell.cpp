#include "Cell.h"
#include "Ocean.h"

Cell::Cell(Pair p, Ocean* oc) :
	crd(p), ocean(oc), obj(nullptr) {};

void Cell::init(Pair p, Ocean* oc)
{
	crd = p;
	ocean = oc;
}

void Cell::setObject(Object* obj)
{
	this->obj = obj;
}

Object* Cell::getObject() const
{
	return obj;
}

Pair Cell::getCrd() const
{
	return crd;
}

Ocean* Cell::getOcean() const
{
	return ocean;
}