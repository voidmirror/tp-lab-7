#pragma once
#ifndef _PREY_H_
#define _PREY_H_

#include "common.h"
#include "object.h"
#include "cell.h"
#include "ocean.h"

class Cell;
class Ocean;

class Prey : public Object {
	friend Cell;
	friend Ocean;
protected:
	static const char name = PREY_N;
	static int count;
	static int reproduce_time;
public:
	Prey(Cell* _cell);
	~Prey() {};
	void move();
	void reproduce();
	void live();
	char getName();
	static void death_counter();
};

#endif