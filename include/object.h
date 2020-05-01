#pragma once
#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "common.h"



class Cell;

class Object {
protected:
	Cell* cell;
	
public:
	Object(Cell* = nullptr);
	~Object() {};
	virtual void live() = 0;
	virtual char getName() = 0;
	void setCell(Cell*);
	Cell* getCell();
};

#endif