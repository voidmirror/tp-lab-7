#include "Cell.h"

Cell::Cell(Couple c, Object* obj) {
	couple = c;
	object = obj;
}

Couple Cell::getCouple() {
	return couple;
}

void Cell::init(Couple c, Object* obj) {
	couple = c;
	object = obj;
}

ObjType Cell::getObjectType() {
	if (object != nullptr) {
		return object->getObjectType();
	}
	else {
		return EMPTY;
	}
}

Object* Cell::getObject() {
	return object;
}

void Cell::setObject(Object* obj) {
	object = obj;
}

Object* Cell::createObj(ObjType type) {
	Object* obj = nullptr;
	switch (type)
	{
	case PREY:
		obj = new Prey;
		break;
	case PREDATOR:
		obj = new Predator;
		break;
	default:
		break;
	}
	obj->setCell(this);
	this->setObject(obj);
	return obj;
}
