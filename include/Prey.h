#pragma once

#include"Animal.h"


class Prey : public Animal {
public:
	Prey(Cell *cell = nullptr) : Animal(cell) { type = ObjType::PREY; restLifetime = PREY_LT; }
	void live();
private:
};
