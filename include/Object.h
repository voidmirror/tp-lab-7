#pragma once
#include <string>

class Cell;

#define STONE_N '.'
#define PREY_N 'f'
#define PREDATOR_N 'S'

enum class ObjType { STONE, PREY, PREDATOR };

class Object
{
protected:
	Cell* cell;
	ObjType type;
	int lifespan;
public:
	Object(Cell*, ObjType);
	ObjType getType();
	Cell* getCell();
	void setCell(Cell*);
	void setLifespan(int);
	virtual char getChar() = 0;
	virtual bool live() = 0;
};

