#pragma once
#ifndef _PREDATOR_H_
#define _PREDATOR_H_

#include "common.h"
#include "object.h"
#include "cell.h"
#include "ocean.h"

class Cell;
class Ocean;

class Predator : public Object {
	friend Cell;
	friend Ocean;
protected:
	static const char name = PREDATOR_N;
	static int count;
	static int reproduce_time;
public:
	Predator(Cell* _cell);
	~Predator() {};
	void move();
	void reproduce();
	void live();
	char getName();
	int getCount();
};

#endif