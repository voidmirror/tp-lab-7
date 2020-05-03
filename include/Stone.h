#ifndef STONE_H
#define STONE_H

#include "Object.h"

class Stone : public Object
{
public:
	Stone(Cell* c);
	void live();
};

#endif