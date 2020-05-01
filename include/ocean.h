#pragma once
#ifndef _OCEAN_H_
#define _OCEAN_H_

#include "cell.h"
#include <vector>

class Ocean {
private:
	Cell** cells;
	vector<Object*> stuff;
public:
	Ocean();
	~Ocean();
	void init();
	void print() const;
	void addObjects(int,int,int);
	void run(int);
	void addObject(Object*);
	void deleteObject(Object*);
	Cell* getFreeCell(Pair);
	Cell* getPreyCell(Pair);
};

#endif