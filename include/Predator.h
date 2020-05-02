#pragma once
#include <string>
#include "Object.h"

class Predator : public Object
{
	int fullness;
	int fullness_by_prey;
	int capacity;
	int fullness_to_reproduce;
public:
	Predator(Cell* cell, int capacity, int initial_fullness, int fullness_to_reproduce, int fullness_by_prey);
	Action live(Object_type up, Object_type down, Object_type left, Object_type right) override;
	std::string draw() override;
	int get_fullness();
	int get_fullness_by_prey();
	int get_capacity();
	int get_fullness_to_reproduce();
protected:
	Action move(Object_type up, Object_type down, Object_type left, Object_type right);
	Action reproduce(Object_type up, Object_type down, Object_type left, Object_type right);
};

