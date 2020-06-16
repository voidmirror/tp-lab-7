#ifndef PREY_H
#define PREY_H

#include "Additional.h"

class Cell;

class Prey  : public Object{
public:
	Prey() = default;
	Prey(Cell* cell);
	virtual void live();
	std::pair<int, int> findNewCell();
	void produce();
	void move();
protected:
	static int preyLifeDuration;
	int countDaysToDie;
};

#endif