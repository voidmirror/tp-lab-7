#pragma once
#include "Cell.h"

class Prey : public Object{
protected:
	int lifetime;
	int dividefreq;
public:
	Prey();
	bool checkEmptyness(Pair crd);
	bool step(Dir dir, Object* obj);
	void divide();
	void move();
	void live();
};
