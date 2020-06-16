#include "Predator.h"
#include "Cell.h"
#include "Object.h"

Predator::Predator(Cell* cell) : Object(cell)
{
	lifetime = LTPredator;
	type = ObjectType::PREDATOR;
	reproduce_time = RPTPREDATOR;
};
bool Predator::live()
{
	if (!lifetime--)
		return false;
	fed = eat();
	reproduce_time--;
	if (fed && reproduce_time == 0)
	{
		reproduce();
		reproduce_time = RPTPREDATOR;
	}
	if (reproduce_time == 0)
		reproduce_time = RPTPREDATOR;
	return true;
}


bool Predator::eat()
{
	Cell* aim = cell->findPrey();
	if (aim != nullptr)
	{
		aim->getObject()->setLifetime(0);
		return true;
	}
	return false;
}

void Predator::move()
{
	Cell* empty_cell = cell->findEmpty();
	if (empty_cell)
	{
		cell->setObject(nullptr);
		cell = empty_cell;
		empty_cell->setObject(this);
	}
}

void Predator::reproduce()
{
	Cell* empty_cell = cell->findEmpty();
	if (empty_cell)
	{
		auto* child = new Predator(empty_cell);
		empty_cell->setObject(child);
		empty_cell->getOcean()->setstuff(child);
	}
}