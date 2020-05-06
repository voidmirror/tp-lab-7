#pragma once
#include "ocean.h"
#include "object.h"

class Prey : public Object
{
private:
	size_t lifeTime;
	size_t reproduceTime;
public:
	Prey(Cell* c);
	void live();
	void move();
	void reproduce();
	void die();
};