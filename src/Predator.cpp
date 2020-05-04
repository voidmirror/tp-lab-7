#include <time.h>
#include <vector>

#include "Cell.h"
#include "Ocean.h"
#include "Object.h"
#include "Stone.h"
#include "Prey.h"
#include "Predator.h"


#include "Additional.h"

int Predator::predatorLifeDuration = 10;
short Predator::dieFromStarvation = -3;

Predator::Predator(Cell* cell) : Prey() {
	this->cell = cell;
	alive = true;
	countDaysToDie = predatorLifeDuration;
	fullness = 3;
	type = ObjectType::PREDATOR;
}

void Predator::live() {
	if (countDaysToDie == 0 || fullness == dieFromStarvation ) {
		kill();
		cell->getOcean()->decPred();
		return;
	}
	if (fullness < 0) {
		eat();
	}
	else {
		int choice = rand() % 10;
		if (choice == 0) {
			produce();
		}
		else if (choice == 1) {
			eat();
		}
		else {
			move();
		}
	}
	countDaysToDie--;
	fullness--;
}


std::pair<int, int> Predator::findFood() {
	std::pair<int, int> crd = cell->getCoordinates();
	int x = crd.first;
	int y = crd.second;

	std::pair<int, int> size = cell->getOcean()->getSize();


	std::vector<std::pair<int, int>> preyCells;
	std::vector<std::pair<int, int>> offset = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
	for (int i = 0; i < 4; i++) {
		int nx = x + offset[i].first;
		int ny = y + offset[i].second;
		if (nx >= 0 && ny >= 0 && nx < size.first && ny < size.second) {
			if (cell->getOcean()->isEmpty({ nx, ny }) == 0 && cell->getOcean()->getCell({ nx, ny })->getObject()->getType() == ObjectType::PREY)
			{
				preyCells.push_back({ nx, ny });
			}
		}
	}
	if (preyCells.size() == 0) {
		return { 1'000'000, 0 };
	}
	else {
		return preyCells[rand() % preyCells.size()];
	}
}

void Predator::eat() {
	std::pair<int, int> from = cell->getCoordinates();
	std::pair<int, int> to = findFood();
	if (to.first == 1'000'000)
		return;
	cell->getOcean()->getCell(to)->getObject()->kill();
	cell->getOcean()->decPrey();
	cell->getOcean()->moveObject(this, from, to);
	fullness = 3;
}

void Predator::produce() {
	std::pair<int, int> crd = findNewCell();
	if (crd.first != 1'000'000) {
		cell->getOcean()->addObject(crd, ObjectType::PREDATOR);
	}
}