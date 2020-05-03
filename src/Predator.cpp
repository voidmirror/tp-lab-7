#include "Predator.h"

Predator::Predator(Cell* cell) : Prey(cell) {
	this->lifetime = kPredLifeTime;
	this->hungerlevel = kHungryLevel;
	type = ObjectType::PREDATOR;
}

bool Predator::hunt() {
	Pair coord = this->cell->get_coord();
	Cell* preycell = this->cell->get_ocean()->prey_cell(coord);

	if (preycell == nullptr)
		return false;

	this->cell->get_ocean()->delete_object(preycell->get_object());
	this->cell->clear_cell(); 
	preycell->set_object(this);
	this->set_cell(preycell);
	hungerlevel = hungerlevel + 2;
	return true;
}

void Predator::live() {
	if (lifetime > 0 && hungerlevel > 0) {
		if (this->hunt() == false) {
			this->move();
			hungerlevel--;
		}
		lifetime--;
		if (reproducetime == 0 && hungerlevel >= 10)
			this->reproduce();
		else
			reproducetime--;		
	}
	else 
		this->die();
}
