#include "Object.h"
#include "Cell.h"

Object::Object(Cell* cell) {
	alive = true;
	setCell(cell);
}

Object::~Object() {

}

void Object::setCell(Cell* cell) {
	if (this->cell) {
		this->cell->setObject(nullptr);
	}
	this->cell = cell;
	cell->setObject(this);
}

char Object::getObjectType(){
	return '.';
}

bool Object::isAlive() {
	return alive;
}

void Object::die() {
	alive = false;
	cell->setObject(nullptr);
	cell = nullptr;
}