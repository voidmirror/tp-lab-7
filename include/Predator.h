#pragma once

#include "Ocean.h"
#include "Prey.h"
class Prey;
class Cell;
class Ocean;

class Predator : public Prey {
	friend Cell;
	friend Ocean;
protected:
	int hungerlevel;
public:
	Predator(Cell*);
	~Predator() {};
	void live();
	bool hunt();
};
