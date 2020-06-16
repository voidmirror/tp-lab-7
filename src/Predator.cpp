#include "Predator.h"

Predator::Predator(Cell* cell_) : Prey(cell_) 
{
	days_of_life = DAYS_OF_LIFE_PREDATOR;
	spawn_time = REPRODUCE_TIME_PREDATOR;
	type = ObjType::PREDATOR;
	symbol = PREDATOR_N;
}

bool Predator::live() 
{
	if (!days_of_life-- || hungry_time == MAX_TIME_WITHOUT_FOOD || count_preys  >= MAX_COUNT_PREY_IN_PERIOD)
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
		spawn_time--;
		if (spawn_time == 0)
		{
			if (hungry_time == 0)
			{
				spawn();
				spawn_time = REPRODUCE_TIME_PREDATOR;
			}
		}
		count_preys = 0;
		return true;
	}
}

void Predator::move()
{	
	if (!fed_up)
	{
		Cell* food = cell->try_find_cell_with_prey();
		if (food != nullptr)
		{
			count_preys++;
			food->get_object()->set_days_of_life(0);
			hungry_time = 0;
		}
		else
		{
			hungry_time++;
		}
	}
	else
	{
		fed_up = false;
	}

	Cell* new_cell = cell->try_find_empty_cell(false);
	if (new_cell)
	{
		cell->set_object(nullptr, false, type);
		cell = new_cell;
		new_cell->set_object(this, false, type);
	}
}

void Predator::spawn() 
{
	Cell* new_cell = cell->try_find_empty_cell(true);
	if (new_cell)
	{
		auto* child = new Predator(new_cell);
		new_cell->set_object(child, true, type);
	}
}

void Predator::easy_prey()
{
	count_preys++;
	hungry_time = 0;
	fed_up = true;
}
