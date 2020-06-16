#include "Object.h"

Object::Object(Cell* cell) {
	this->cell = cell;
};

void Object::setCell(Cell* cell) {
	this->cell = cell;
}

Cell* Object::getCell() {
	return cell;
}