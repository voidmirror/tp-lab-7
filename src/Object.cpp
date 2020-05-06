#include "Object.h"

Object::Object() : cell(nullptr){
}

Cell* Object::getCell() {
	return cell; 
}

void Object::setCell(Cell* cell) {
	this->cell = cell;
}

ObjType Object::getType() {
	return type;
}


