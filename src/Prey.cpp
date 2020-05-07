#include "Prey.h"

Prey::Prey(){
	
	this->lifeTime = preyLifetime;
	this->breedTime = breedTimecommon;
	this->type = ObjType::PREY;
}
void Prey::live() {
	if (lifeTime > 0) {
		this->move();
		lifeTime--;
		if (breedTime == 0)
			this->breed();
		else
			breedTime--;
	}
	else
		this->die();
}
void Prey::die() {
	this->cell->getOcean()->delObj(this);
}
void Prey::breed() {
	breedTime = breedTimecommon;
	this->cell->getOcean()->addObjs(this->cell->getObj()->getType(), 1);
}
void Prey::move() {
	pair coord = this->cell->getCrd();
	Cell* newcell = this->cell->getOcean()->freeCellcheck(coord);
	if (newcell != nullptr) {
		newcell->setObj(this);
		this->cell->killMe();
		this->setCell(newcell);
	}
}