#include "Predator.h" //fix

Predator::Predator(Cell* cell) :Object(cell) {
	this->lifetime = PredatorLifeTime;
	type = ObjectType::PREDATOR;
};

void Predator::Live() {
	if (Eat() != true && lifetime > 2)
		lifetime -= 2;
	else
		lifetime--;
	Move();
	if (lifetime < 0.2 * PredatorLifeTime)
		Copulation();
};

char Predator::GetSymbol() {
	return PREDATOR_S;
};

void Predator::Move() {
	Cell* newcell = cell->FindEmptyNeighbour();
	if (newcell != nullptr) {
		this->GetCell()->Move();
		newcell->SetObject(this);
		this->cell = newcell;
	}
};

bool Predator::Eat() {
	Pair cord = cell->Cords();
	Cell* victim = cell->FindPreyNeighbour();
	if (victim && !victim->GetObject()->IsLive() && victim->GetObject()->GetType() == ObjectType::PREY) {
		lifetime += 3;
		victim->GetObject()->Die();
		victim->GetObject()->SetLifetime(0);
		return true;
	}
	return false;
};

void Predator::Copulation() {
	Cell* newcell = cell->FindEmptyNeighbour();
	if (newcell) {
		Object* newpredator = new Predator(newcell);
		newcell->SetObject(newpredator);
		cell->GetOcean()->AddStuff(newpredator);
	}
};

