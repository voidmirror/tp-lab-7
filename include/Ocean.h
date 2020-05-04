#pragma once
#include <vector>
#include <string>
#include "Common.h"

class Object;
class Cell;
class Ocean {
private:
	Cell** cells; 
	std::vector<Object*> stuff;
	int stone_q = 0; // counter for amount of stones used to stop the simulation in run() function
public:
	Ocean();
	bool isCellEmpty(Pair crd);
	Cell* checkForPreyAround(Pair crd);
	Cell* checkAround(Pair crd);
	void moveObj(Pair new_crd, Object* obj_p);
	void addObj(ObjType type, Pair coord);
	void removeObj(Object* obj_p);
	void addAll(int stone_q, int prey_q, int predator_q); // q stands for quantity
	void print();
	void run();
};