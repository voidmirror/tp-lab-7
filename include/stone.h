#pragma once
#ifndef _STONE_H_
#define _STONE_H_

#include "common.h"
#include "object.h"
#include "cell.h"

class Cell;

class Stone : public Object {
	friend Cell;
protected:
	static const char name = STONE_N;
	static int count;
public:
	Stone(Cell* _cell);
	~Stone() {};
	void live();
	char getName();
	int getCount();
};

#endif