#include <time.h>
#include <iostream>
#include <vector>

#include "Cell.h"
#include "Ocean.h"
#include "Object.h"
#include "Stone.h"
#include "Prey.h"
#include "Predator.h"


#include "Additional.h"

int Prey::preyLifeDuration = 10;

Prey::Prey(Cell* cell) : Object(cell){
	countDaysToDie = preyLifeDuration;
	type = ObjectType::PREY;
}
void Prey::live() {
	if (countDaysToDie == 0) {
		kill();
		cell->getOcean()->decPrey();
		return;
	}
	int choice = rand() % 10;
	if (choice == 0) {
		produce();
	}
	else {
		move();
	}
	countDaysToDie--;
}

std::pair<int, int> Prey::findNewCell() {
	std::pair<int, int> crd = cell->getCoordinates();
	int x = crd.first;
	int y = crd.second;

	std::pair<int, int> size = cell->getOcean()->getSize();

	
	std::vector<std::pair<int, int>> freeCells;
	std::vector<std::pair<int, int>> offset = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
	for (int i=0; i < 4; i++){
		int nx = x + offset[i].first;
		int ny = y + offset[i].second;
		if (nx >= 0 && ny >= 0 && nx < size.first && ny < size.second) {
			if (cell->getOcean()->isEmpty({ nx, ny })) {
				freeCells.push_back({ nx, ny });
			}
		}
	}
	if (freeCells.size() == 0) {
		return { 1'000'000, 0 };
	}
	else {
		return freeCells[rand() % freeCells.size()];
	}
}
void Prey::produce() {
	std::pair<int, int> crd = findNewCell();
	if (crd.first != 1'000'000) {
		cell->getOcean()->addObject(crd, ObjectType::PREY);
	}
}
void Prey::move() {
	std::pair<int, int> from = cell->getCoordinates();
	std::pair<int, int> to = findNewCell();
	if (to.first == 1'000'000)
		return;
	cell->getOcean()->moveObject(this, from, to);
}
