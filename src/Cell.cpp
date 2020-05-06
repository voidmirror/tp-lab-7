#include "Cell.h"
#include "Ocean.h"

Cell::Cell(){
	crd = { 0, 0 };
	obj = nullptr;
	ocean = nullptr;
}

void Cell::init(Pair p, Ocean *oc) {
	crd = p;
	ocean = oc;
}

Object* Cell::getObject(){
	return obj;
}

Pair Cell::getCoord(){
	return crd;
}

Ocean* Cell::getOcean(){
	return ocean;
}

void Cell::setObject(Object* obj){
	this->obj = obj;
}

void Cell::killMe(){
	if (obj != nullptr){
		ocean->removeObject(this->obj);
		delete obj;
		this->obj = nullptr;
	}
}
