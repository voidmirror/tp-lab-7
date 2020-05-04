#include "Cell.h"
#include "Ocean.h"
#include "Object.h"
#include "Stone.h"
#include "Prey.h"
#include "Predator.h"


#include "Additional.h"

Object::Object() {
	cell = nullptr;
	alive = true;
}

Object::Object(Cell* cell) {
	this->cell = cell;
	alive = true;
}

void Object::setCell(Cell* cell) {
	this->cell = cell;
}

ObjectType Object::getType() const {
	return type;
}

bool Object::isDead() const {
	return alive == 0;
}
void Object::kill() {
	alive = 0;
	cell->removeObject();
}