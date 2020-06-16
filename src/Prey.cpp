#include "Prey.h"
#include "Cell.h"
#include "Ocean.h"

void Prey::move() {
	Cell* neighbour = cell->getNeighbour();
	if (neighbour) {
		cell->setObject(nullptr);
		setCell(neighbour);
	}
}

void Prey::reproduce() {
	Cell* neighbour = cell->getNeighbour();
	if (neighbour) {
		cell->getOcean()->addObject(ObjType::PREY, PREY_LIFESPAN, PREY_REPRODUCTION, PREY_CAPACITY, neighbour);
		reproductionTimer = reproduction;
	}
}

Prey::Prey(Cell* cell, int lifespan, int reproduction): Object(cell) {
	type = ObjType::PREY;
	this->lifespan = lifespan;
	this->reproduction = reproduction;
	this->reproductionTimer = reproduction;
}

Prey::~Prey() {

}

int Prey::live() {
	if (!alive) return 0;
	reproductionTimer--;
	if (reproductionTimer == 0) {
		reproduce();
		if (!reproductionTimer)reproductionTimer++;
	}
	else {
		move();
	}
	lifespan--;
	if (lifespan == 0) {
		die();
	}
	return alive;
}

char Prey::getObjectType() {
	return PREY_N;
}

void Prey::die() {
	alive = false;
	cell->getOcean()->reducePrey();
	cell->setObject(nullptr);
	cell = nullptr;
}