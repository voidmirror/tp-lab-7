#ifndef OBJECT_H
#define OBJECT_H

#include "common.h"

class Cell;

class Object {
protected:
	Cell* cell;

public:
	Object(Cell* cell = nullptr);
	~Object() {};
	virtual void live() = 0;
	virtual char getName() = 0;
	void setCell(Cell* cell);
	Cell* getCell();
};

#endif 