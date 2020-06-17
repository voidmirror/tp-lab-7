#ifndef OCEAN_H
#define OCEAN_H

#include <vector>
#include "common.h"
#include "Cell.h"

using namespace std;

class Ocean
{
private:
	unsigned int counter[3];// [0]-stones, [1]-preys, [2]-predators
	vector<vector<Cell*>> cells;
	vector<Object*> objects;
public:
	Ocean();
	~Ocean();
	void run(size_t iter);
	void print() const;
	void addObject(Pair pos, ObjType type);
	void deleteObject(Pair pos);
	//Pair isOccupiedByPos(Pair pos);
	Pair findParamByPos(Pair pos, string param) const;
	Cell* getCellbyPos(Pair pos);
	bool isDying() const;
};



#endif