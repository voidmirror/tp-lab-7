#ifndef STONE_H
#define STONE_H
#include "Additional.h"

class Cell;

class Stone : public Object {
public:
	Stone(Cell* cell);
	void live() override;
};

#endif