#ifndef OCEAN_H
#define OCEAN_H

#include "Cell.h"
#include <vector>

class Ocean {
private:
	Cell** cells;
	std::vector<Object*> stuff;
public:
	Ocean();
	~Ocean();
	void init();
	void print() const;
	void addObjects(int stoneNum, int preyCnt, int predatorCnt);
	void run(int speed);
	void addObject(Object* object);
	void deleteObject(Object* object);
	Cell* getFreeCell(Pair coord);
	Cell* getPreyCell(Pair coord);
};

#endif 