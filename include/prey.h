#pragma once
#ifndef _PREY_H_
#define _PREY_H_



#include "ocean.h"

class Cell;
class Ocean;

class Prey : public Object {
	friend Cell;
	friend Ocean;
protected:
	const char name = PREY_N;
	int reproducetime;
	int lifetime;
public:
	Prey(Cell*);
	~Prey() {};
	void move();
	void reproduce();
	void live();
	void suicide();
	char getName();
};

#endif