#include "Predator.h"
#include "Cell.h"
#include "Ocean.h"

bool Predator::hunt() {
	Cell* neighbour = cell->getNeighbour(true);
	if (neighbour && neighbour->getObject())
	{
		neighbour->getObject()->die();
		cell->setObject(nullptr);
		setCell(neighbour);
		capacityRest = capacity;
		return true;
	}
	return false;
}

void Predator::reproduce() {
	Cell* neighbour = cell->getNeighbour();
	if (neighbour) {
		cell->getOcean()->addObject(ObjType::PREDATOR, PREDATOR_LIFESPAN, PREDATOR_REPRODUCTION, PREDATOR_CAPACITY, neighbour);
	}
}

void Predator::move() {
	Cell* neighbour = cell->getNeighbour(false);
	if (neighbour) {
		cell->setObject(nullptr);
		setCell(neighbour);
	}
}

Predator::Predator(Cell* cell, int lifespan, int reproduction, int capacity) : Prey(cell, lifespan, reproduction) {
	type = ObjType::PREDATOR;
	this->capacity = capacity;
	this->capacityRest = capacity;
}

Predator::~Predator() {

}

int Predator::live() {
	if (!alive) return 0;
	reproductionTimer--;
	if (!hunt()) {
		move();
	}
	if (reproductionTimer == 0 && capacityRest == capacity) {
		reproduce();
		if (!reproductionTimer)reproductionTimer++;
	}
	lifespan--;
	capacityRest--;
	if (lifespan == 0 || capacityRest == 0) {
		die();
	}
	return alive;
}

char Predator::getObjectType() {
	return PREDATOR_N;
}

void Predator::die() {
	alive = false;
	cell->getOcean()->reducePredators();
	cell->setObject(nullptr);
	cell = nullptr;
}