#ifndef PREY_H
#define PREY_H

#include "Ocean.h"

class Cell;
class Ocean;

class Prey : public Object {
	friend Cell;
	friend Ocean;
protected:
	const char name = PREY_TILE;
	int reproducetime;
	int lifetime;
public:
	Prey(Cell* cell);
	~Prey() {};
	void move();
	void reproduce();
	void live();
	void die();
	char getName();
};

#endif 