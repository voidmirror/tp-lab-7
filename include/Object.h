#ifndef OBJECT_H
#define OBJECT_H

#include "Common.h"

#define STONE_N '#'
#define CORAL_H '*'
#define PREY_N 'f'
#define PREDATOR_N 'S'

enum class ObjType { STONE, CORAL, PREY, PREDATOR };

class Cell;

class Object
{
protected:
	ObjType type;
	Cell* cell;
	bool alive;
public:
	Object(Cell* cell);
	virtual ~Object();
	virtual int live() = 0;
	void setCell(Cell* cell);
	virtual char getObjectType();
	bool isAlive();
	virtual void die();
};

#endif 
