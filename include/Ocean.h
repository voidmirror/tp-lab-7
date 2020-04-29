#pragma once

#include "Cell.h"

#define FishWeight 7

class Ocean {
private:
	int preyCtr = 0, predCtr = 0;
	int h, w;
	Cell** cells;
	vector<Object*> stuff;
public:
	Ocean(int h, int w);
	void addObjects();
	void print();
	void step();
	int getObjNum();
	void printNumbers();
	Couple getNumbers();
	~Ocean();
};