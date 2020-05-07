#include"Predator.h"

Predator::Predator (){
	this->lifeTime = predatorLifeTime;
	this->fullness = commonfull;
	type = ObjType::PREDATOR;

}
void Predator::hunt() {
	pair coord = this->cell->getCrd();
	Cell* preycell = this->cell->getOcean()->preyCellcheck(coord);

	if (preycell == nullptr)
	{
		this->move();
			return;
	}

	this->cell->getOcean()->delObj(preycell->getObj());
	preycell->setObj(this);
	this->cell->killMe();
	
	this->setCell(preycell);
	this->fullness += 5;
	return;
}
void Predator::live() {
	if (lifeTime > 0 && fullness>0) {
		if (fullness < 13) {
			this->hunt();
		}
		else {
			this->move();
		}
		fullness--;
		lifeTime--;

		if (breedTime == 0 && fullness >= 17)
			this->breed();
		else
			breedTime--;
	}
	else
		this->die();
}