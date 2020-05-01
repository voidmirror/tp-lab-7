#include "Prey.h" //fix

Prey::Prey(Cell* cell) :Object(cell) {
	this->lifetime = PreyLifeTime;
	this->type = ObjectType::PREY;
};

void Prey::Live() {
	Move();
	if (lifetime < 0.3 * PreyLifeTime)
		Copulation();
	lifetime--;
};

char Prey::GetSymbol() {
	return PREY_S;
};

void Prey::Move() {
	Cell* newcell = cell->FindEmptyNeighbour();
	if (newcell) {
		this->GetCell()->Move();
		newcell->SetObject(this);
		this->cell = newcell;
	}
};

void Prey::Copulation() {
	Cell* newcell = cell->FindEmptyNeighbour();
	if (newcell) {
		Object* newprey = new Prey(newcell);
		newcell->SetObject(newprey);
		cell->GetOcean()->AddStuff(newprey);
	}
};

