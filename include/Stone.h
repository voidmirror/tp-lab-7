#pragma once //fix

#include "Object.h"

class Stone :public Object {
	friend Cell;
public:
	Stone(Cell* cell);
	~Stone() {};
	void Live();
	char GetSymbol();
};
