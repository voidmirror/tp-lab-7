#ifndef PREY_H
#define PREY_H

#include "Object.h"

class Prey :public Object {
protected:
	int lifespan;
	int reproduction;
	int reproductionTimer;
	void move();
	void reproduce();
public:
	Prey(Cell* cell, int lifespan, int reproduction);
	~Prey();
	virtual int live();
	virtual char getObjectType() override;
	virtual void die() override;
};


#endif
