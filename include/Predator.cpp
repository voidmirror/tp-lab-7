#include "Predator.h"
#include "Ocean_Enums.h"
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>

Predator::Predator(Cell* cell, int capacity, int initial_fullness, int fullness_to_reproduce, int fullness_by_prey) : Object(cell)
{
	this->capacity = capacity;
	this->fullness = initial_fullness;
	this->fullness_to_reproduce = fullness_to_reproduce;
	this->fullness_by_prey = fullness_by_prey;
	this->type = Object_type::predator;
}

Action Predator::live(Object_type up, Object_type down, Object_type left, Object_type right)
{
	fullness--;
	
	if (fullness == 0) // check death
	{
		return Action::die;
	}
	
	Action reproduce_try = this->reproduce(up, down, left, right); // try to reproduce
	if (reproduce_try != Action::nothing)
	{
		this->fullness + this->fullness_by_prey < this->capacity ? this->fullness = this->fullness + this->fullness_by_prey : this->fullness = this->capacity;
		return reproduce_try;
	}
	
	if (up == Object_type::prey)    // try to eat
	{
		return Action::eat_up;
	}
	if (down == Object_type::prey)
	{
		return Action::eat_down;
	}
	if (left == Object_type::prey)
	{
		return Action::eat_left;
	}
	if (right == Object_type::prey)
	{
		return Action::eat_right;
	}

	return this->move(up, down, left, right);

}

std::string Predator::draw() 
{
	return "P";
}

int Predator::get_fullness() 
{
	return this->fullness;
}

int Predator::get_fullness_by_prey()
{
	return this->fullness_by_prey;
}

int Predator::get_capacity()
{
	return this->capacity;
}

int Predator::get_fullness_to_reproduce()
{
	return this->fullness_to_reproduce;
}

Action Predator::move(Object_type up, Object_type down, Object_type left, Object_type right)
{
	std::vector<Action> moves;
	if (up == Object_type::empty_space)
	{
		moves.push_back(Action::move_up);
	}
	if (down == Object_type::empty_space)
	{
		moves.push_back(Action::move_down);
	}
	if (left == Object_type::empty_space)
	{
		moves.push_back(Action::move_left);
	}
	if (right == Object_type::empty_space)
	{
		moves.push_back(Action::move_right);
	}
	if (moves.size() == 0)
	{
		return Action::nothing;
	}

	//srand(time(NULL));
	return moves[rand() % moves.size()];
	
}

Action Predator::reproduce(Object_type up, Object_type down, Object_type left, Object_type right)
{
	if (this->fullness >= this->fullness_to_reproduce)
	{
		if (up == Object_type::empty_space)
		{
			return Action::reproduce_up;
		}
		if (down == Object_type::empty_space)
		{
			return Action::reproduce_down;
		}
		if (left == Object_type::empty_space)
		{
			return Action::reproduce_left;
		}
		if (right == Object_type::empty_space)
		{
			return Action::reproduce_right;
		}
	}
	else
	{
		return Action::nothing;
	}
}