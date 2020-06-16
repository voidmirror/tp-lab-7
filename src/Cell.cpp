#include "Cell.h"
#include "Ocean.h"

Cell::Cell() : crd({0, 0}), obj(nullptr), ocean(nullptr){
}

Pair Cell::getCrd() {
	return crd;
}

Object* Cell::getObj() {
	return obj;
}

Ocean* Cell::getOcean() {
	return ocean;
}

void Cell::init(Pair crd, Ocean* ocean)  {
	this->crd = crd;
	this->ocean = ocean;
}

void Cell::setObj(Object* obj) {
	this->obj = obj;
}

void Cell::setCrd(Pair crd) {
	this->crd = crd;
}

void Cell::killMe() {
	ocean->removeObj(this->obj);
	delete obj;
	this->obj = nullptr;
}