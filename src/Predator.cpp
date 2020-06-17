#include "Predator.h"

Predator::Predator() {
	type = PREDATOR;
	breeding = 90 + (rand() % 3) * 10; 
	int liveTimer = rand() % 10;
	lifetime = 150 + liveTimer * 20;
}

void Predator::breed() {
	Ocean* ocean = cell->getOcean();
	Pair coordinates = cell->getCoordinates();
	Cell* cell = ocean->checkCells(coordinates);
	if (cell != nullptr) {
		ocean->addObject(PREDATOR, cell->getCoordinates());
		breed = tick;
	}
}

void Predator::kill() {
	Ocean* ocean = cell->getOcean();
	Pair coordinates = cell->getCoordinates();
	Cell* preyCell = nullptr;
	preyCell = ocean->checkPrey(coordinates);
	if (preyCell != nullptr) {
		preyCell->deleteItem();
		stomach += 80;
	}
}

void Predator::exist() {
	if (stomach <= 0) { 
		kill();
		move();

	}
	else { 
		move();
		if (tick - breed == breeding) {
			breed(); 
		}
	}
	tick++;
	stomach--;
	if (tick == lifetime || stomach < -80) {
		cell->deleteItem();
	}
}