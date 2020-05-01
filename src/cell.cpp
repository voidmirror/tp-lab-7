#include "cell.h"

void Cell::init(Pair coord, Ocean* ocean) {
	this->coord = coord;
	this->ocean = ocean;
}

Object* Cell::getObject(){
	return obj;
}

Ocean* Cell::getOcean() {
	return ocean;
}

void Cell::setObject(Object* obj) {
	this->obj = obj;
}

void Cell::clearCell() {
	obj = nullptr;
}

Pair Cell::getCoord() {
	return coord;
}