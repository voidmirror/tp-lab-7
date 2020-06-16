#pragma once

#include "Prey.h"

class Predator : public Prey
{
private:
	int hungry_time = 0;
	bool fed_up = false;
	int count_preys = 0;

public:
	Predator(Cell* cell_);
	~Predator() = default;
	bool live() override;
	void move() override;
	void spawn() override;
	void easy_prey() override;
};
