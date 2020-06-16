#pragma once
#include "Common.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


enum  ObjType { STONE, PREY, PREDATOR };

class Cell;
class Ocean;
class Object
{
	friend Ocean;
	friend Cell;
protected:

	Cell* cell;
	int life = 0;
	char symbol;
	ObjType type;
	int lifeChance;
public:

	Object(Cell* NewCell)
	{
		cell = NewCell;
		lifeChance = chance;
	}
	char getSymbol()
	{
		return symbol;
	}
	Object* getObject()
	{
		return this;
	}
	void live()
	{
		life++;
	}
	void setCell(Cell* NewCell)
	{
		cell = NewCell;
	}
};


class Stone :public Object
{
	friend Ocean;
	friend Cell;
protected:

public:
	Stone(Cell* NewCell) :Object(NewCell)
	{
		this->type = STONE;
		this->symbol = '#';
	}
};
class Prey :public Object
{
	friend Ocean;
	friend Cell;
protected:
public:
	Prey(Cell* NewCell) :Object(NewCell)
	{
		this->type = PREY;
		this->symbol = 'f';
	}

};
class Predator :public Object
{
	friend Ocean;
	friend Cell;
protected:

public:
	Predator(Cell* NewCell) :Object(NewCell)
	{
		this->type = PREDATOR;
		this->symbol = 'S';

	}
};