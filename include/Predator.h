#pragma once
#include "Object.h"
#include "Prey.h"

class Predator : public Prey{
protected:
	int stomach;
	int hunger;
public:
	Predator();
	void divide();
	void kill();
	void live();
};
