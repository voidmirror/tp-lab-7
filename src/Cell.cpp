#include "Cell.h"
#include "Ocean.h"
#include<iostream>

bool Cell::isOccupied()
{
	if (obj == nullptr){
		return false;
	}
	else {
		return true;
	}

}


void Cell::init(Pair p, Ocean* oc) {
	crd.x = p.x;
	crd.y = p.y;
	ocean = oc;
}


Object* Cell::getObject() const {
	return obj;
}


void Cell::setObject(Object* obj){
	this->obj = obj;
}


char Cell::getIcon() const {
	if (obj == nullptr) {
		return icons[static_cast<int>(ObjType::FREE)];
	}
	else {
		return icons[static_cast<int>(obj->getType())];
	}
	
}


Ocean* Cell::getOcean() const {
	return this->ocean;
}


Pair Cell::getCoord() const {
	return crd;
}


void Cell::killMe(){
	obj = nullptr;
}