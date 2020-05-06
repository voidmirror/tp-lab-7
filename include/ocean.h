#pragma once
#include "common.h"
#include "cell.h"
#include "prey.h"
#include "predator.h"
#include "stone.h"
#include "coral.h"
#include <vector>

class Ocean
{
	friend Cell;
	friend Object;
private:
	Cell** cells;
	std::vector<Object*> stuff;
public:
	Ocean();
	~Ocean();
	void print();
	void addObjects(int n, ObjType t);
	void run();
	void delObj(Cell* c);
	Cell* findEmpty(Pair p);
	Cell* findPrey(Pair p);
};