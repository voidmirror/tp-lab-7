#include "Prey.h"

Prey::Prey(Cell* c) : Object(c)
{
	life = life_span_prey;
	species = ObjType::PREY;
	spawnFrequency = spawn_freq_prey;
	symb = PREY_N;
}

void Prey::move()
{
	Cell* cell_to_move = cell->findEmptyCellNear();
	if (cell_to_move != nullptr)
	{
		cell->setObject(nullptr);
		cell_to_move->setObject(this);
		cell = cell_to_move;
	}
}

void Prey::spawn()
{
	Cell* cell_to_spawn = cell->findEmptyCellNear();
	if (cell_to_spawn != nullptr)
	{
		Prey* child_prey = new Prey(cell_to_spawn);
		cell_to_spawn->setObject(child_prey);
		cell->getOcean()->addObject(child_prey);
	}
}

void Prey::live()
{
	life--;
	if (life < 0)
		alive = false;
	else 
	{
		if (life % spawn_freq_prey == 0)
			this->spawn();
		this->move();
	}
}
