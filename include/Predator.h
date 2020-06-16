#ifndef PREDATOR_H
#define PREDATOR_H

#include "Prey.h"

class Predator : public Prey
{
protected:
	bool hungry;
	int hungry_period;
public:
	Predator(Cell* c);
	void live();
	void spawn();
	void hunt();
};

#endif