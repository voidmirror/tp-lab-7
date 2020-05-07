#pragma once
#include "common.h"
#include <vector>
#include <string>

class Object;
class Cell;
class Ocean {
private:
	Cell** cells;
	std::vector<Object*> stuff;
	
public:
	Ocean();
	void addObjs(ObjType type, int q);
	void delObj(Object* obj);
	Cell* freeCellcheck(pair crd);
	Cell* preyCellcheck(pair crd);
	
	void print();
	void run();
};