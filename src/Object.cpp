#include "Object.h"

Object::Object(Cell* cell){
	this->cell = cell;
}

void Object::setCell(Cell* cell) {
	this->cell = cell;
}

Cell* Object::getCell() const {
	return cell;
}

ObjType Object::getType() const {
	return type;
}

char Object::getSymbol() const {
	return symbol;
}