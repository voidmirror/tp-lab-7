#ifndef _OCEAN_H_
#define _OCEAN_H_

#include "common.h"
#include "Cell.h"
#include <list>

class Ocean
{
	friend Object;
	friend Cell;
private:
	Cell ** cells;
	std::list<Object*> stuff;

public:
	Ocean();
	~Ocean();
	void print();
	void addObjects(int num_object, ObjType type);
	void move();
	void eat();
	void die();
	void reproduce();
};
#endif