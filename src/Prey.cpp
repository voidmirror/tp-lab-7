#include <iostream>
#include "Prey.h"

Prey::Prey() {
	type = PREY;
	breeding = 30 + (rand() % 5) * 5 ;
	int liveTimer = rand() % 2; 
	lifetime = 100 + liveTimer * 20; 
}

bool Prey::moveOneStep(Directions direction, Object* object) {
	Pair coordinates = cell->getCoordinates(); 
	Ocean* ocean = cell->getOcean();
	switch (direction) {
	case UP:
		if (coordinates.x - 1 >= 0 && ocean->isCellEmpty({ coordinates.x - 1, coordinates.y })) {
			ocean->moveObject({ coordinates.x - 1, coordinates.y }, this);
			return 1;
		}
	case DOWN:
		if (coordinates.x + 1 < M && ocean->isCellEmpty({ coordinates.x + 1, coordinates.y })) {
			ocean->moveObject({ coordinates.x + 1, coordinates.y }, this);
			return 1;
		}
	case RIGHT:
		if (coordinates.y + 1 < N && ocean->isCellEmpty({ coordinates.x, coordinates.y + 1})) {
			ocean->moveObject({ coordinates.x, coordinates.y + 1 }, this);
			return 1;
		}
	case LEFT:
		if (coordinates.y - 1 >= 0 && ocean->isCellEmpty({ coordinates.x, coordinates.y - 1})) {
			ocean->moveObject({ coordinates.x, coordinates.y - 1 }, this);
			return 1;
		}
	}
	return 0;
}

void Prey::breed() {
	Pair coordinates = cell->getCoordinates();
	Ocean* ocean = cell->getOcean();
	Cell* cell = ocean->checkCells(coordinates);

	if (cell != nullptr) {
		ocean->addObject(PREY, cell->getCoordinates());
		breed = tick;
	}
}

void Prey::move() {

	switch (rand() % 5) {
	case UP:
		if (moveOneStep(UP, this)) break;
		else if (moveOneStep(RIGHT, this)) break;
		else if (moveOneStep(DOWN, this)) break;
		else if (moveOneStep(LEFT, this)) break;
		break;
	case DOWN:
		if (moveOneStep(DOWN, this)) break;
		else if (moveOneStep(LEFT, this)) break;
		else if (moveOneStep(UP, this)) break;
		else if (moveOneStep(RIGHT, this)) break;
		break;
	case RIGHT:
		if (moveOneStep(RIGHT, this)) break;
		else if (moveOneStep(DOWN, this)) break;
		else if (moveOneStep(LEFT, this)) break;
		else if (moveOneStep(UP, this)) break;
		break;
	case LEFT:
		if (moveOneStep(LEFT, this)) break;
		else if (moveOneStep(UP, this)) break;
		else if (moveOneStep(RIGHT, this)) break;
		else if (moveOneStep(DOWN, this)) break;
		break;
	case HALT:
		break;
	}
}

void Prey::exist() {
	move();
	tick++;
	if (tick == lifetime) {
		cell->deleteItem();
	}
	if (tick - breed == breeding) {
		breed(); 
	}
}