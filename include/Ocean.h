#ifndef OCEAN_H
#define OCEAN_H

#include "Common.h"
#include "Cell.h"
#include "Object.h"

#include <vector>
#include <string>

using std::vector;
using std::string;

class Ocean
{
private:
	vector<vector<Cell*>>cells;
	vector<Object*>stuff;
	vector<Object*>nextIteration;
	int preys, predators;
public:
	Ocean(int stones = 0, int preys = 0, int predators = 0);
	~Ocean();
	void printOcean();
	void run();
	string nextStep();
	void addObject(ObjType type, int lifespan, int reproduction, int capacity, Cell* cell);
	Cell* getCell(coord_t x, coord_t y);
	void reducePrey();
	void reducePredators();
};

#endif 
