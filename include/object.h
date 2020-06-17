#pragma once
#include "common.h"

#define STONE_N '#'
#define CORAL_N '*'
#define PREY_N 'f'
#define PREDATOR_N 'S'

enum class ObjType { STONE, CORAL, PREY, PREDATOR };

class Cell;

class Object
{
protected:
	Cell* cell;
	ObjType type;
public:
	Object(Cell* c);
	void setCell(Cell* c);
	Cell* getCell();
	ObjType getType();
	virtual void live() = 0;
	virtual void die();
};