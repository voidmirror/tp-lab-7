#pragma once
#include "ocean.h"
#include "object.h"

class Predator : public Object
{
private:
	size_t lifeTime;
	size_t reproduceTime;
	size_t hunger;
public:
	Predator(Cell* c);
	void live();
	void move();
	void reproduce();
	void die();
	void eat();
};
