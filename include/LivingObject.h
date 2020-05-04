#pragma once
#include "Object.h"
#include <vector>

enum Directions { UP, RIGHT, DOWN, LEFT };

class Cell;

class LivingObject :
	public Object
{
protected:	
	void move(int x, int y);
	void motion();
	virtual bool checkCell(Cell* cellTo) = 0;
	std::vector<Cell*> getNeirboringCells();
public:
	LivingObject(int x, int y,  Ocean* ocean);
	LivingObject(coord coordinates, Ocean* ocean);	
	virtual void live() = 0;
	virtual void eat(Cell* cell) = 0;
	void die();
	virtual void multiply() = 0;
	void birth();	
};

