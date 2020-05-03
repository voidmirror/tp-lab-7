#include "Prey.h"
#include "Predator.h"


Prey::Prey(Cell* cell) :Object(cell) {
	this->cell = cell;
	this->lifetime = preyLifetime;
	this->reproducetime = preyReproducetime;
}

void Prey::live() {
	if (lifetime > 0) {
		this->move();
		if (reproducetime == 0) this->reproduce();
		lifetime--;
		reproducetime--;
	}
	else {
		this->die();
	}
}

void Prey::move() {
	Cell* newcell = this->cell->getOcean()->getFreeCell(this->cell->getCoord());
	if (newcell != nullptr) {
		newcell->setObject(this);
		this->cell->clearCell();
		this->setCell(newcell);
	}
}

void Prey::reproduce() {
	reproducetime = 2;
	Cell* newcell = this->cell->getOcean()->getFreeCell(this->cell->getCoord());
	if (newcell != nullptr) {
		Prey* newprey = new Prey(newcell);
		newcell->setObject(newprey);
		this->cell->getOcean()->addObject(newprey);
	}
}

void Prey::die() {
	this->cell->getOcean()->deleteObject(this);
}

char Prey::getName() {
	return this->name;
}




Predator::Predator(Cell* cell) : Prey(cell) {
	this->cell = cell;
	this->lifetime = predatorLifetime;
	this->hungerlevel = predatorHungerLevel;
	this->reproducetime = predatorReproducetime;
}

void Predator::live() {
	if (lifetime > 0) {
		if (!this->hunt()) this->move();
		if (reproducetime == 0 && hungerlevel >= 2) this->reproduce();
		lifetime--;
		hungerlevel--;
		reproducetime--;
	}
	else {
		this->die();
	}
}

void Predator::reproduce() {
	reproducetime = 5;
	hungerlevel = 0;
	Cell* newcell = this->cell->getOcean()->getFreeCell(this->cell->getCoord());
	if (newcell != nullptr) {
		Predator* newprey = new Predator(newcell);
		newcell->setObject(newprey);
		this->cell->getOcean()->addObject(newprey);
	}
}

bool Predator::hunt() {
	Cell* preycell = this->cell->getOcean()->getPreyCell(this->cell->getCoord());
	if (preycell != nullptr) {
		preycell->getOcean()->deleteObject(preycell->getObject());
		this->cell->clearCell();
		preycell->setObject(this);
		this->setCell(preycell);
		this->hungerlevel = this->hungerlevel + 3;
		return true;
	}
	else {
		return false;
	}

}

char Predator::getName() {
	return this->name;
}