#pragma once

#include "Common.h"
#include "Cell.h"
#include <list>

class Object;
class Cell;

class Ocean {
	friend class Cell;
private:
	Cell** cells;
	std::list<Object*> stuff;
public:
	Ocean();
	~Ocean();
	void print() const;
	void addObjects(ObjType type, unsigned int count);
	void run();
	void setStuff(Object* obj);
	void deleteObject(Object* obj);
	Cell* EmptyCellAroundIt(Pair coord);
	Cell* CellWithPreyAroundIt(Pair coord);
	Cell* CellWithPredatorAroundIt(Pair coord);
	int count_stone = 0;
	int count_prey = 0;
	int count_predator = 0;
};