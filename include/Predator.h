#ifndef PREDATOR_H
#define PREDATOR_H

#include "Additional.h"

class Cell;

class Predator : public Prey {
private:
	short fullness;
	static short dieFromStarvation;
	static int predatorLifeDuration;
public: 
	Predator(Cell* cell);
	std::pair<int, int> findFood();
	void live();
	void eat();
	void produce();
};

#endif