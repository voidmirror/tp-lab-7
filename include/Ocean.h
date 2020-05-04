#pragma once

#include "Common.h"
#include "Object.h"
#include "Cell.h"
#include <list>

using namespace std;

class Object;
class Cell;
class Ocean
{
	friend Cell;
	friend Object;
private:
	vector<vector<Cell*>> cells;
	list<Object*> stuff;
	
public:
	Ocean();
    void print();
	void addObjects(int numStone, int numPrey, int numPred);
	void run();
	void eat();
	void Kill();
	void reproduction();
	
};