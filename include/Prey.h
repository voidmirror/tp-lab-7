#pragma once
#include "common.h"
#include "Object.h"

class Prey : public Object
{
protected:
	int reproduce_timeout;

	void move();
	bool reproduce();
public:
	Prey(Cell*, ObjType);
	void setLifespan(int);
	char getChar();
	bool live();
};

