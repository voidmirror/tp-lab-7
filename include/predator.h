#pragma once
#ifndef _PREDATOR_H_
#define _PREDATOR_H_



#include "ocean.h"
#include "prey.h"

class Prey;
class Cell;
class Ocean;

class Predator : public Prey {
	friend Cell;
	friend Ocean;
protected:
	const char name = PREDATOR_N;
	int reproducetime;
	int hungerlevel;
public:
	Predator(Cell*);
	~Predator() {};
	void live();
	void reproduce();
	bool hunt();
	char getName();
};

#endif