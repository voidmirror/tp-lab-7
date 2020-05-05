#pragma once

#include"Animal.h"

class Predator : public Animal {
public:
	Predator(Cell *cell = nullptr) : Animal(cell) { type = ObjType::PREDATOR; restLifetime = PREDATOR_LT; ltWithoutEat = PREDATOR_LT_WITHOUT_EAT;  }
	void live();
private:
	int ltWithoutEat;
};