#pragma once //fix

#include "Object.h"
#include "Cell.h"

class Predator : public Object{
	friend Cell;
public:
	Predator(Cell* cell);
	~Predator() {};
	void Copulation();
	void Live();
	void Move();
	bool Eat();
	char GetSymbol();
};
