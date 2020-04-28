#include "cell.h"

void Cell::init(Pair p, Ocean* oc) {
	crd = p;
	ocean = oc;
}

Object* Cell::getObject() const {
	return obj;
}

Ocean* Cell::getOcean() const {
	return ocean;
}

void Cell::setObject(Object* _obj) {
	obj = _obj;
}

void Cell::clearCell() {
	obj = nullptr;
}

Pair Cell::getCrd() {
	return crd;
}