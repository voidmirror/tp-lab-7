#pragma once

#include <iostream>
#include "common.h"

#define STONE_N '#'
#define PREY_N 'f'
#define PREDATOR_N 'S'

enum class ObjectType { STONE, PREY, PREDATOR };

class Cell;
class Ocean;

class Object
{
	friend Ocean;
	friend Cell;
protected:

	Cell* cell;
	ObjectType type;
	char s;
	size_t reproduce_time;
	int lifetime;

public:
	Object(Cell* = nullptr);
	void setCell(Cell*);
	Object* getObject();
	Cell* getCell();
	char getsymbol();
	ObjectType gettype();
	virtual bool live() = 0;
	virtual void move() {};
	virtual void reproduce() {};
	void setLifetime(int);
};