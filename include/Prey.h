#ifndef PREY_H
#define PREY_H

//#include "Object.h"
#include "Cell.h"

//class Cell;

class Prey : public Object
{
protected:
	int spawnFrequency;
	int life;
public:
	Prey(Cell* c);
	void live();
	void move();
	void spawn();
};

#endif