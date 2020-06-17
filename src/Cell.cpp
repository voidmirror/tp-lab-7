#include "Cell.h"

Cell::Cell(Pair p, Ocean* oc) :
	crd(p),
	obj(nullptr),
	ocean(oc) {}

void Cell::init(Pair p, Ocean* oc) {
	crd = p;
	ocean = oc;
}

void Cell::setObject(Object* obj) {
	this->obj = obj;
}

Object* Cell::getObject() const {
	return obj;
}

Pair Cell::getCoord() const {
	return crd;
}
