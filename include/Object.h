#pragma once
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
	void setCell(Cell* cell);
	virtual void live() = 0;
	
};