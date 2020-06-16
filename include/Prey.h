#pragma once

#include "Ocean.h"

class Cell;
class Ocean;

class Prey : public Object {
	friend Cell;
	friend Ocean;
protected:
	int reproducetime;
	int lifetime;
public:
	Prey(Cell*);
	~Prey() {};
	void live(); 
	void move();
	void reproduce();
	void die();
};
