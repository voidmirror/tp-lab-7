#pragma once
#include <string>
#include "Object.h"

class Prey : public Object
{
	int age;
	int age_to_reproduce;
	int chance_to_reproduce;
	int age_to_die;
public:
	Prey(Cell* cell, int age_to_reproduce, int age_to_die, int chance_to_reproduce);
	Action live(Object_type up, Object_type down, Object_type left, Object_type right) override;
	std::string draw() override;
	int get_age_to_die();
	int get_age();
protected:
	Action move(Object_type up, Object_type down, Object_type left, Object_type right);
	Action reproduce(Object_type up, Object_type down, Object_type left, Object_type right);
};

