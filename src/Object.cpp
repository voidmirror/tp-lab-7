#include "Object.h"

Object::Object(Cell* cell) {
	this->cell = cell;
}

Object::~Object() {}

void Object::setCell(Cell* cell) {
	this->cell = cell;
}

Cell* Object::getCell() const {
	return this->cell;
}

void Object::moveToCell(Cell* cell) {
	if (this->cell) {
		this->cell->setObject(nullptr);
	}
	setCell(cell);
	if (cell) {
		cell->setObject(this);
	}
}

char Object::getSymbol() const {
	return '?';
}
