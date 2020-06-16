#pragma once
#ifndef _OCEAN_H_
#define _OCEAN_H_

#include "common.h"
#include "cell.h"
#include <vector>

class Ocean {
private:
	Cell** cells;
	vector<Object*> stuff;
public:
	Ocean();
	~Ocean();
	void print() const;
	void addObjects(int);
	void removeObjects();
	void run(int);
	Cell* getFreeCell(Pair);
	void addChild(Object*);
	Cell* hunting(Pair);
};

#endif