#pragma once

#include "Prey.h"

class Predator : public Prey {
private:
	int hunger = 0;
	bool NeedToEat = false;
public:
	Predator(Cell* cell);
	~Predator() = default;
	bool live() override;
	void reproduce() override;
	void move() override;
	void EatenByPredator() override;
};