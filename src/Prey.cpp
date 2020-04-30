#include "Prey.h"
#include "Cell.h"
#include "Object.h"

Prey::Prey(Cell* cell) : Object(cell)
{
	lifetime = LTPrey;
	type = ObjectType::PREY;
	reproduce_time = RPTPREY;
}

bool Prey::live()
{
	if (!lifetime--)
		return false;
	move();
	if (reproduce_time == 0)
	{
		reproduce();
		reproduce_time = RPTPREY;
	}
	reproduce_time--;
	return true;
}

void Prey::move()
{
	Cell* empty_cell = cell->findEmpty();
	Object* object = cell->getObject();
	if (empty_cell!=nullptr)
	{
		cell->setObject(nullptr);
		cell = empty_cell;
		empty_cell->setObject(object);
	}
}

void Prey::reproduce()
{
	Cell* empty_cell = cell->findEmpty();
	if (empty_cell)
	{
		auto* child = new Prey(empty_cell);
		empty_cell->setObject(child);
		empty_cell->getOcean()->setstuff(child);
	}
}