#include "Predator.h"

Predator::Predator() {
	type = PREDATOR;
	breedingtime = 90 + (rand() % 3) * 10; 
	int life_multiplier = rand() % 10;
	lifetime = 150 + life_multiplier * 20;
}

void Predator::breed() {
	Ocean* ocean_p = cell->getOcean();
	Pair crd = cell->getCrd();
	Cell* cell_p = ocean_p->checkAround(crd);
	if (cell_p != nullptr) {
		ocean_p->addObj(PREDATOR, cell_p->getCrd());
		breed_pulse = pulse;
	}
}

void Predator::hunt() {
	Ocean* ocean_p = cell->getOcean();
	Pair crd = cell->getCrd();
	Cell* prey_cell_p = nullptr;
	prey_cell_p = ocean_p->checkForPreyAround(crd);
	if (prey_cell_p != nullptr) {
		prey_cell_p->killMe();
		fullness += 90;
	}
}

void Predator::live() {
	if (fullness <= 0) { // if the predator is hungry, it starts hunting
		hunt();
		move();
		hunt();
	}
	else { // if not, it acts like prey
		move();
		if (pulse - breed_pulse == breedingtime) {
			breed(); 
		}
	}
	pulse++;
	fullness--;
	if (pulse == lifetime || fullness < -90) {
		cell->killMe();
	}
}