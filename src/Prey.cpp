#include <iostream>
#include "Prey.h"

Prey::Prey() {
	type = PREY;
	breedingtime = 60 + (rand() % 3) * 10 ; //breeds every 60 (+ random number in range from 0 to 60) pulses
	int life_multiplier = rand() % 10; // random lifetime generator
	lifetime = 100 + life_multiplier * 20; // from 100 to 300 pulses 
}

bool Prey::moveOneStep(Directions direction, Object* obj) {
	Pair old_crd = cell->getCrd(); // old coord 
	Ocean* ocean_p = cell->getOcean();
	switch (direction) {
	case UP:
		if (old_crd.x - 1 >= 0 && ocean_p->isCellEmpty({ old_crd.x - 1, old_crd.y })) {
			ocean_p->moveObj({ old_crd.x - 1, old_crd.y }, this);
			return 1;
		}
	case DOWN:
		if (old_crd.x + 1 < M && ocean_p->isCellEmpty({ old_crd.x + 1, old_crd.y })) {
			ocean_p->moveObj({ old_crd.x + 1, old_crd.y }, this);
			return 1;
		}
	case RIGHT:
		if (old_crd.y + 1 < N && ocean_p->isCellEmpty({ old_crd.x, old_crd.y + 1})) {
			ocean_p->moveObj({ old_crd.x, old_crd.y + 1 }, this);
			return 1;
		}
	case LEFT:
		if (old_crd.y - 1 >= 0 && ocean_p->isCellEmpty({ old_crd.x, old_crd.y - 1})) {
			ocean_p->moveObj({ old_crd.x, old_crd.y - 1 }, this);
			return 1;
		}
	}
	return 0;
}

void Prey::breed() {
	Ocean* ocean_p = cell->getOcean();
	Pair crd = cell->getCrd();
	Cell* cell_p = ocean_p->checkAround(crd);
	if (cell_p != nullptr) {
		ocean_p->addObj(PREY, cell_p->getCrd());
		breed_pulse = pulse;
	}
}

void Prey::move() {
	//---debug:---//
	//moveOneStep(UP, this);
	//moveOneStep(DOWN, this);
	//moveOneStep(RIGHT, this);
	//moveOneStep(LEFT, this);
	//------------//

	switch (rand() % 5) { // The direction is random. If there is an obstacle on a set direction, the prey starts looking for other avaliable directions clockwise.
	case UP:
		if (moveOneStep(UP, this)) break;
		else if (moveOneStep(RIGHT, this)) break;
		else if (moveOneStep(DOWN, this)) break;
		else if (moveOneStep(LEFT, this)) break;
		break; // if none of the functions were called - an object is trapped and cannot move, break
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

void Prey::live() {
	move();
	pulse++;
	if (pulse == lifetime) {
		cell->killMe();
		
	}
	if (pulse - breed_pulse == breedingtime) {
		breed(); 
	}
}