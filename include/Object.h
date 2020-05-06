#ifndef OBJECT_H
#define OBJECT_H

#include "common.h"

enum ObjType { STONE = 0, PREY, PREDATOR };

class Cell;

class Object
{
protected:
	Cell* cell;
public:
	Object(Cell*);
	virtual void live() = 0;
	virtual ObjType getType() const = 0 ;
	void setCell(Cell*);
};

#endif