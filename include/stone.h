#pragma once
#ifndef _STONE_H_
#define _STONE_H_



#include "cell.h"

class Cell;

class Stone : public Object {
	friend Cell;
protected:
	const char name = STONE_N;
	
public:
	Stone(Cell*);
	~Stone() {};
	char getName();
	void live();
};
#endif