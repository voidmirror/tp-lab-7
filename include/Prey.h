#pragma once

#include "Object.h"

class Prey : public Object {
public:
	Prey(Cell* cell);
	~Prey() = default;
	bool live() override;
	void reproduce() override;
	void move() override;
};