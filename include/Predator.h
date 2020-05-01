#ifndef PREDATOR_H
#define PREDATOR_H

#include "Prey.h"

class Predator :public Prey {
protected:
	int capacity;
	int capacityRest;
	bool hunt();
	void reproduce();
	void move();
public:
	Predator(Cell* cell, int lifespan, int reproduction, int capacity);
	~Predator();
	virtual int live()override;
	virtual char getObjectType() override;
	virtual void die() override;
};

#endif // !PREDATOR_H
