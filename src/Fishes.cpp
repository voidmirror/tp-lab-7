#include <iostream>
#include <cstdlib>
#include "Fishes.h"
#include "Object.h"
#include "Cell.h"
#include "Ocean.h"

Stone::Stone(Cell* cell) : Object(cell) {};

void Stone::live() {};

ObjType Stone::getType() const
{
	return type;
}
//===================================

Prey::Prey(Cell* cell) : Object(cell)
{
	lifeTime = rand() % 10 + 15;
	newReproduction();
}

void Prey::newReproduction()
{
	reproduceTime = rand() % 5;
}

void Prey::reproduce()
{
	Pair freeCell = cell->getOcean()->findParamByPos(cell->getCrd(), "Free");
	if ((reproduceTime == 0) && ((freeCell.x != 0) && (freeCell.y != 0)))
	{
		cell->getOcean()->addObject(freeCell, getType());
		this->newReproduction();
	}
}


ObjType Prey::getType() const
{
	return type;
}

void Prey::move()
{
	Pair freeCell = cell->getOcean()->findParamByPos(cell->getCrd(), "Free");
	if ((freeCell.x == 0) && (freeCell.y == 0))
	{
		return;
	}
	cell->setObject(nullptr);
	cell = cell->getOcean()->getCellbyPos(freeCell);
	cell->setObject(this);
	
}

void Prey::die()
{
	cell->getOcean()->deleteObject(cell->getCrd());
}

void Prey::live()
{
	reproduce();
	move();
	lifeTime--;
	reproduceTime--;
	if (lifeTime == 0)
		die();
}

//=============================

Predator::Predator(Cell* cell)
	: Prey(cell)
{
	hungerTime = 0;
	type = PREDATOR;
}

void Predator::newReproduction()
{
	reproduceTime = rand() % 5 + 13;
}

void Predator::eat()
{
	Pair wrong = { 0, 0 };
	Pair preyCell = cell->getOcean()->findParamByPos(cell->getCrd(), "Prey");
	if((preyCell.x != 0)||(preyCell.y != 0))
		cell->getOcean()->deleteObject(preyCell);
	hungerTime = 0;
}

void Predator::live()
{
	reproduce();
	move();
	hungerTime++;
	lifeTime--;
	reproduceTime--;
	if (hungerTime > 3)
		eat();
	if ((hungerTime > 9) || (lifeTime == 0))
		die();
}