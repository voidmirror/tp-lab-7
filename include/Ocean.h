#pragma once
#include "Cell.h"
#include <list>


class Ocean
{

private:
	Cell **cells;
	std::list<Object*> stuff;
	int lastId = 0;

public:
	Ocean();
	~Ocean();
	int getLastId();
	void print() const;
	void addObjects(std::list<Object*>);
	void addObject(Object* object);
	void killObject(int);
	void randDistribution();
	void randDistribution(std::list<Object*>);
	Cell* getCell(Pair) const;
	void run();
};