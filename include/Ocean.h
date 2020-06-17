#pragma once

#include <vector>
#include <string>
#include "Common.h"

class Object;
class Cell;

class Ocean {

private:
	Cell** cells; 
	std::vector<Object*> oceanObjects;
	int stones = 0; 

public:
	Ocean();
	bool isCellEmpty(Pair coordinates);
	Cell* checkPrey(Pair coordinates);
	Cell* checkCells(Pair coordinates);
	void moveObject(Pair coordinates, Object* object);
	void addObject(ObjectType objectType, Pair coordinates);
	void addAll(int stones, int preys, int predators);
	void deleteObject(Object* object);
	void print();
	void run();
};