#ifndef _OCEAN_H_
#define _OCEAN_H_

//#include "Common.h"
//#include "Cell.h"
#include "Object.h"


#include <list>
#include <vector>


class Ocean
{
private:
	Cell** cells;
	list<Object*> stuff;
public:
	Ocean();
	~Ocean();
	void print() const;
	void addObject(Object* object);
	void addObjects(ObjType species, int amount);
	bool deleteObject(Object* object);
	void run();
	Cell* findEmptyCellNear(Pair crd);
	Cell* findFoodNear(Pair crd);
	int countPreys();
	int countPredators();
};
#endif