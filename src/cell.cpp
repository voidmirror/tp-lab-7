#include "cell.h"



void Cell::init(Pair p, Ocean* oc)
{
	this->coordinates = p;
	this->ocean = oc;
	object = nullptr;
}

Object* Cell::getObject()
{
	return object;
}

void Cell::setObject(Object* obj)
{
	this->object = obj;
}

void Cell::killMe()
{
	object = nullptr;
}

Pair Cell::getCoordinates() {
	return coordinates;
}

Ocean* Cell::getOcean()
{
	return ocean;
}