#pragma once
#include "Common.h"
#include <string>

#define STONE_N '#'
#define PREY_N 'f'
#define PREDATOR_N 'S'

enum class ObjType {STONE,PREY,PREDATOR}; //perenesti v common

class Cell;
class Object{
protected:
	Cell *cell;
	ObjType type;
public:
	Object(Cell* = nullptr);
	virtual void live() = 0; // жизнь объекта
	void setCell(Cell* cell);
	Cell* getCell();
	ObjType getType();
};
