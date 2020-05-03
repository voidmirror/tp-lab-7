#ifndef PREDATOR_H
#define PREDATOR_H

#include "Ocean.h"
#include "Prey.h"

class Prey;
class Cell;
class Ocean;

class Predator : public Prey {
	friend Cell;
	friend Ocean;
protected:
	const char name = PREDATOR_TILE;
	int reproducetime;
	int hungerlevel;
public:
	Predator(Cell* cell);
	~Predator() {};
	void live();
	void reproduce();
	bool hunt();
	char getName();
};

#endif 