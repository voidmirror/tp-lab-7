#pragma once

#include "Object.h"
#include "Cell.h"
#include "Ocean.h"
#include "common.h"

class Cell;
class Ocean;
class Prey : public Object
{
public:
	Prey(Cell* cell);
	bool live() override;
	void move() override;
	void reproduce() override;
};


