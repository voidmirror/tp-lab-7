#pragma once
#include <string>
#include "Common.h"
#include "Cell.h"

class Object {
	
protected:

	Cell* cell;
	ObjectType type;

public:
	Object();

	Cell* getCell();

	void setCell(Cell* cell);

	ObjectType getType();

	virtual void exist() = 0;
};