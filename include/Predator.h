#pragma once
#include "Prey.h"

class Predator : public Prey
{
	bool hungry;
	int starvation;
public:
	Predator(Cell*, ObjType);
	char getChar();
	bool live();
	bool reproduce();
	bool eat();
};

