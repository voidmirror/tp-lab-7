#ifndef STONE_H
#define STONE_H

#include "Cell.h"

class Cell;

class Stone : public Object {
	friend Cell;
protected:
	const char name = STONE_TILE;

public:
	Stone(Cell* cell) : Object(cell) {}
	~Stone() {};
	char getName() {
		return name;
	}
	void live() {};
};
#endif 