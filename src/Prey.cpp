#include "Prey.h"

Prey::Prey(Cell* cell_) : Object(cell_)
{
	days_of_life = DAYS_OF_LIFE_PREY;
	spawn_time = REPRODUCE_TIME_PREY;
	type = ObjType::PREY;
	symbol = PREY_N;
}

bool Prey::live() 
{
	if (!days_of_life--)
	{
		if (spawn_time == 0)
		{
			cell->no_chance();
		}
		return false;
	}
	else
	{
		move();
		if (days_of_life == 0)
		{
			if (spawn_time == 0)
			{
				cell->no_chance();
			}
			return false;
		}
		spawn_time--;
		if (spawn_time == 0)
		{
			spawn();
			spawn_time = REPRODUCE_TIME_PREY;
		}
		return true;
	}
}

void Prey::move()
{
	Cell* new_cell = cell->try_find_empty_cell(false); 
	if (new_cell)
	{
		if (new_cell->get_object() == nullptr)
		{
			cell->set_object(nullptr, false, type);
			cell = new_cell;
			new_cell->set_object(this, false, type);
		}
		else
		{
			days_of_life = 0;
			new_cell->get_object()->easy_prey();
		}
	}
}

void Prey::spawn() 
{
	Cell* new_cell = cell->try_find_empty_cell(true);
	if (new_cell)
	{
		auto* child = new Prey(new_cell);
		new_cell->set_object(child, true, type);
	}
}
