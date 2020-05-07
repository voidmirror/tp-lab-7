#include "Object.h"

Object::Object()  {
	this->cell = nullptr;
	
}

Cell* Object::getCell() {
	return cell;
}

ObjType Object::getType() {
	return type;
}

void Object::setCell(Cell* cell) {
	this->cell = cell;
}