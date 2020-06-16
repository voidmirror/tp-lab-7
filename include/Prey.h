#pragma once

#include "Object.h"

class Prey : public Object
{
public:
	Prey(Cell* cell_);
	~Prey() = default;
	bool live() override;
	void move() override;
	void spawn() override;
};
