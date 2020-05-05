#include "Prey.h"
#include "Cell.h"
#include "Ocean.h"

Prey::Prey(Cell* cell) : Object(cell){
	type = ObjType::PREY;
	symbol = PREY_N;
	reproduce_time = REPRODUCE_TIME_PREY;
	lifespan = LIFESPAN_OF_PREY;
}

bool Prey::live() {
	if (!lifespan--)
		return false;
	else {
		move();
		if (lifespan == 0)
			return false;		
		reproduce_time--;
		if (reproduce_time == 0) {
			reproduce();
			reproduce_time = REPRODUCE_TIME_PREY;
		}
		
		return true;
	}
}

void Prey::reproduce() {
	Cell* temp_cell = cell->findCellToMove();
	if (temp_cell) {
		auto* baby = new Prey(temp_cell);
		temp_cell->setObject(baby);
		temp_cell->getOcean()->setStuff(baby);
		temp_cell->getOcean()->count_prey++;
	}
}

void Prey::move() {
	Cell* temp_cell = cell->findCellToMove();
	if (temp_cell) {
		if (temp_cell->getObj() == nullptr) {
			cell->setObject(nullptr);
			cell = temp_cell;
			temp_cell->setObject(this);
		}
		else {
			lifespan = 0;
			temp_cell->getObj()->EatenByPredator();
		}
	}
}

