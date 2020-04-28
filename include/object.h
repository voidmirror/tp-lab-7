#pragma once
#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "common.h"

#define STONE_N '#'
#define PREY_N 'O'
#define PREDATOR_N 'X'

class Cell;

class Object {
protected:
	Cell* cell;
	int live_time;
public:
	Object(Cell* = nullptr);
	~Object() {};
	virtual void live() = 0; // жизнь объекта
	virtual char getName() = 0;
	int getLiveTime();
	void setCell(Cell*);
	Cell* getCell();
	void setLiveTime(int);
};

#endif