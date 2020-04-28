#include "Context.h"
#include "Inhabitant.h"
#include <iostream>


//Prey

Prey::Prey(Cell* cell) : Object(cell)
{
	lifeTime = 0;
	reproduceTime = 0;
	type = ObjType::PREY;
}

void Prey::Live()
{
	lifeTime++;
	reproduceTime++;

	if (reproduceTime >= reproduceTimeLimit)
	{
		Reproduce();
		reproduceTime = 0;
	}

	if (lifeTime >= lifeTimeLimit)
	{
		Die();
	}
}

void Prey::Reproduce()
{
	cell->ocean->AddObjects(type, 1);
}

void Prey::Die()
{
	cell->ocean->RemoveFromStuff(cell);
}

ObjType Prey::GetType() const
{
	return type;
}

//Predator

Predator::Predator(Cell* cell): Prey(cell)
{
	type = ObjType::PREDATOR;
	hungerLevel = 0;
}

void Predator::Live()
{
	lifeTime++;
	reproduceTime++;
	hungerLevel++;

	//Eating
	size_t x = cell->coordinates.x;
	size_t y = cell->coordinates.y;

	for (size_t d = 0; d < 4; d++)
	{
		size_t newX = (x + dx[d]) % height;
		size_t newY = (y + dy[d]) % width;

		if (cell->ocean->cells[newX][newY].object != nullptr &&
			cell->ocean->cells[newX][newY].object->GetType() == ObjType::PREY)
		{
			Eat(newX, newY);
		}
	}
	
	//Reproduction
	if (reproduceTime >= reproduceTimeLimit && hungerLevel <= hungerLevelLimitForReproduction)
	{
		Reproduce();
		reproduceTime = 0;
	}

	//Dying
	if (lifeTime >= lifeTimeLimit || hungerLevel >= hungerLevelLimit)
	{
		Die();
	}
}

void Predator::Reproduce()
{
	cell->ocean->AddObjects(type, 1);
}

void Predator::Die()
{
	cell->ocean->RemoveFromStuff(cell);
}

void Predator::Eat(size_t x, size_t y)
{
	cell->ocean->RemoveFromStuff(&(cell->ocean->cells[x][y]));
	hungerLevel -= hungerLevelChange;
	if (hungerLevel < 0) hungerLevel = 0;
}

ObjType Predator::GetType() const
{
	return type;
}