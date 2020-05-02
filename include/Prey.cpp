#include "Prey.h"
#include <vector>
#include <cstdlib>
#include <ctime>

Prey::Prey(Cell* cell, int age_to_reproduce, int age_to_die, int chance_to_reproduce) : Object(cell)
{
	this->age_to_reproduce = age_to_reproduce;
	this->chance_to_reproduce = chance_to_reproduce;
	this->age_to_die = age_to_die;
	this->age = 0;
}
Action Prey::live(Object_type up, Object_type down, Object_type left, Object_type right)
{
	this->age++;
	if (this->age >= this->age_to_die) // check death
	{
		return Action::die;
	}

	Action reproduce_try = this->reproduce(up, down, left, right); // try to reproduce
	if (reproduce_try != Action::nothing)
	{
		return reproduce_try;
	}

	return this->move(up, down, left, right);
}

std::string Prey::draw()
{
	return "*";
}

int Prey::get_age_to_die()
{
	return this->age_to_die;
}

int Prey::get_age()
{
	return this->age;
}

Action Prey::move(Object_type up, Object_type down, Object_type left, Object_type right) 
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

Action Prey::reproduce(Object_type up, Object_type down, Object_type left, Object_type right)
{
	srand(time(NULL));
	int reproduce_try = rand() % 100;
	if (reproduce_try > chance_to_reproduce)
	{
		return Action::nothing;
	}
	if (this->age >= this->age_to_reproduce && this->age-this->age_to_reproduce % 3 == 0)
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
