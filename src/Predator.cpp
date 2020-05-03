#include "Predator.h"

Predator::Predator(Cell* c) : Prey(c)
{
	life = life_span_predator;
	species = ObjType::PREDATOR;
	spawnFrequency = spawn_freq_predator;
	symb = PREDATOR_N;
	hungry = false;
	hungry_period = without_eat;
}

void Predator::hunt()
{
	Cell* food = cell->findFoodNear();
	if (food != nullptr)
	{
		hungry = false;
		hungry_period = 0;
		food->getOcean()->deleteObject(food->getObject());
		food->setObject(this);
	}
	else
	{
		hungry = true;
		hungry_period++;
	}
}

void Predator::spawn()
{
	Cell* cell_to_spawn = cell->findEmptyCellNear();
	if (cell_to_spawn != nullptr)
	{
		Prey* child_pred = new Predator(cell_to_spawn);
		cell_to_spawn->setObject(child_pred);
		cell->getOcean()->addObject(child_pred);
	}
}

void Predator::live()
{
	life--;
	this->hunt();
	if ((hungry_period >= without_eat) || life < 0)
		alive = false;
	else
	{
		if (life % spawn_freq_predator == 0 && hungry == false)
			this->spawn();
		this->move();
	}
}
