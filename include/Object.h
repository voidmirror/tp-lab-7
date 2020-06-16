#pragma once
#include <string>
#include "Common.h"
#include "Cell.h"

class Object {
	
protected:
	Cell* cell;
	ObjType type;
public:
	Object();
	Cell* getCell();
	ObjType getType();
	virtual void live() = 0;
	void setCell(Cell* cell);
};