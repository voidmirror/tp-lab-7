#include "prey.h"

Prey::Prey(Cell* cell) : Object(cell)
{
	type = ObjType::PREY;
	lifeTime = 0;
	reproduceTime = 0;
}

void Prey::live()
{
	if (reproduceTime == rtLimit)
	{
		reproduce();
		reproduceTime = 0;
	}
	if (lifeTime == ltLimit)
	{
		die();
		return;
	}
	lifeTime++;
	reproduceTime++;
	move();
}

void Prey::move()
{
	Pair c = cell->getCoordinates();
	Cell* newCell = cell->getOcean()->findEmpty(c);
	if (newCell != nullptr)
	{
		cell->setObject(nullptr);
		newCell->setObject(this);
		cell = newCell;
	}
}

void Prey::reproduce()
{
	Pair c = cell->getCoordinates();
	Cell* newCell = cell->getOcean()->findEmpty(c);
	if (newCell != nullptr)
	{
		Prey* newPrey = new Prey(newCell);
		newCell->setObject(newPrey);
		newCell->getOcean()->addObjects(1, ObjType::PREY);
	}
}

void Prey::die() {
	cell->killMe();
	cell->getOcean()->delObj(cell);
}