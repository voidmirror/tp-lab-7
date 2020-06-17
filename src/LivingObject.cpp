#include "LivingObject.h"

LivingObject::LivingObject(Cell* cell) :
	Object(cell),
	health(0) {}

void LivingObject::setHealth(int health) {
	this->health = health;
}

int LivingObject::getHealth() const {
	return health;
}
