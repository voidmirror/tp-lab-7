#include "predator.h"

Predator::Predator(Cell* cell) : Object(cell)
{
	type = ObjType::PREDATOR;
	lifeTime = 0;
	reproduceTime = 0;
	hunger = 0;
};

void Predator::live()
{
	eat();
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
	if (hunger == hLimit) {
		die();
		return;
	}
	lifeTime++;
	reproduceTime++;
	hunger++;
	move();
}


void Predator::eat()
{
	Pair c = cell->getCoordinates();
	Cell* prey = cell->getOcean()->findPrey(c);
	if (prey != nullptr)
	{
		prey->getObject()->die();
		hunger = 0;
	}
}

void Predator::move()
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

void Predator::reproduce()
{
	Pair c = cell->getCoordinates();
	Cell* newCell = cell->getOcean()->findEmpty(c);
	if (newCell != nullptr)
	{
		Predator* newPredator = new Predator(newCell);
		newCell->setObject(newPredator);
		newCell->getOcean()->addObjects(1, ObjType::PREDATOR);
	}
}

void Predator::die() {
	cell->killMe();
	cell->getOcean()->delObj(cell);
}