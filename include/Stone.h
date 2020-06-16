#pragma once

#include "Cell.h"

class Cell;

class Stone : public Object {
	friend Cell;
public:
	Stone(Cell*);
	~Stone() {};
	void live();
};
