#include "Predator.h"
#include "Ocean.h"

Predator::Predator(Cell* cell) : Prey(cell) {
	symbol = PREDATOR_N;
	type = ObjType::PREDATOR;
	lifespan = LIFESPAN_OF_PREDATOR;
	reproduce_time = REPRODUCE_TIME_PREDATOR;
}

bool Predator::live() {
	if (!lifespan-- || hunger == MAX_DAYS_WITHOUT_FOOD)
		return false;
	else {
		move();
		reproduce_time--;
		if (reproduce_time == 0)
			if (hunger == 0) {
				reproduce();
				reproduce_time = REPRODUCE_TIME_PREDATOR;
			}
	
		return true;
	}
}

void Predator::move() {
	if (!NeedToEat) {
		Cell* food = cell->findCellToEat();
		if (food != nullptr) {
			food->getObj()->setLifespanForEat(0);
			hunger = 0;
		}
		else
			hunger++;
	}
	else
		NeedToEat = false;

	Cell* temp_cell = cell->findCellToMove();
	
	if (temp_cell) {
		cell->setObject(nullptr);
		cell = temp_cell;
		temp_cell->setObject(this);
	}
}

void Predator::reproduce() {
	Cell* temp_cell = cell->findCellToMove();
	if (temp_cell) {
		auto* baby = new Predator(temp_cell);
		temp_cell->setObject(baby);
		temp_cell->getOcean()->setStuff(baby);
		temp_cell->getOcean()->count_predator++;
	}
}

void Predator::EatenByPredator() {
	hunger = 0;
	NeedToEat = true;
}