#include "Prey.h"

Prey::Prey(Cell* cell) :Object(cell) {
	this->cell = cell;
	this->lifetime = kPreyLifeTime;
	this->reproducetime = kReproTime;
	this->type = ObjectType::PREY;
}

void Prey::live() {
	if (lifetime > 0) {
		this->move();
		lifetime--; 
		if (reproducetime == 0)
			this->reproduce();
		else
			reproducetime--;
	}
	else 
		this->die();
}

void Prey::reproduce() {
	reproducetime = kReproTime;
	this->cell->get_ocean()->add_objects(this->cell->get_object()->get_type(), 1);
}

void Prey::die() {
	this->cell->get_ocean()->delete_object(this);
}

void Prey::move() {
	Pair coord = this->cell->get_coord();
	Cell* newcell = this->cell->get_ocean()->free_cell(coord);
	if (newcell != nullptr) {
		newcell->set_object(this);
		this->cell->clear_cell();
		this->set_cell(newcell);
	}
}

		