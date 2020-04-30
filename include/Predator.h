#pragma once

#include "Object.h"
#include "Cell.h"
#include "Ocean.h"
#include "common.h"

class Predator : public Object
{

public:
	Predator(Cell* cell);
	bool live() override;
	bool eat();
	void move() override;
	void reproduce() override;

private:
	bool fed = false;
};

