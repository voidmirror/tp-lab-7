#pragma once
#include <vector>
#include <string>
#include "Common.h"
#include "Cell.h"

class Object;
class Cell;

class Ocean{
private:
	Cell **cells;
	std::vector<Object*> stuff;
public:
	Ocean();
	bool checkEmptyness(Pair crd);
	Cell* checkAll(Pair crd);
	Cell* checkAllForFood(Pair crd);
	void addObject(Object* obj);
	void addManyObjects(ObjType objtype, int num);
	void removeObject(Object* obj);
	void moveObject(Object* obj, Pair newcrd);
	void print();
	void run();
};
