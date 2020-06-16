#include "Coral.h"

Coral::Coral(Cell* cell_) : Stone(cell_)
{
	spawn_time = REPRODUCE_TIME_CORAL;
	days_of_life = DAYS_OF_LIFE_CORAL;
	type = ObjType::CORAL;
	symbol = CORAL_N;
}

bool Coral::live()
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
		spawn_time--;
		if (spawn_time == 0)
		{
			spawn();
			spawn_time = REPRODUCE_TIME_CORAL;
		}
	}
	return true;
}
void Coral::spawn()
{
	Cell* new_cell = cell->try_find_empty_cell(true);
	if (new_cell)
	{
		auto* child = new Coral(new_cell);
		new_cell->set_object(child, true, type);
	}
}
