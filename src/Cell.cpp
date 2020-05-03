#include "Cell.h"

void Cell::init(Pair coord, Ocean* ocean) {
	this->coord = coord;
	this->ocean = ocean;
}

void Cell::clearCell() {
	obj = nullptr;
}

void Cell::setObject(Object* obj) {
	this->obj = obj;
}

Object* Cell::getObject() {
	return obj;
}

Ocean* Cell::getOcean() {
	return ocean;
}

Pair Cell::getCoord() {
	return coord;
}