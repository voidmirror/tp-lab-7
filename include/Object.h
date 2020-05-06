#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "common.h"

#define STONE_N '#'
#define PREY_N 'f'
#define PREDATOR_N 'S'

enum class ObjType { STONE, PREY, PREDATOR };

class Cell;
class Ocean;
#include <iostream>
class Object
{
	friend Ocean;
	friend Cell;
protected:

	Cell * cell;
	ObjType type;
	char s;
	int lifetime=0;

public:
	Object(Cell * = nullptr);
	void setCell(Cell*);

	Object* getObject();
	char getsymbol();
	ObjType getType();
	void live(); // жизнь объекта
};




class Stone :public Object
{
	friend Ocean;
	friend Cell;
protected:
public:
	Stone(Cell* c) :Object(c)
	{
		type = ObjType::STONE;
		s = STONE_N;
	}
};

class Prey :public Object
{
	friend Ocean;
	friend Cell;
protected:
public:
	Prey(Cell* c) :Object(c)
	{
		
		type = ObjType::PREY;
		s = PREY_N;
	}

};

class Predator :public Object
{
	friend Ocean;
	friend Cell;
protected:
public:
	Predator(Cell* cell) :Object(cell)
	{
		
		type = ObjType::PREDATOR;
		s = PREDATOR_N;
	}
};

#endif