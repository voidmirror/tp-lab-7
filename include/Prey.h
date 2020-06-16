#pragma once //fix

#include "Object.h"
#include "Cell.h"

class Prey :public Object {
public:
	Prey(Cell* cell);
	~Prey() {};
	void Live();
	char GetSymbol();
	void Move();
	void Copulation();
};
