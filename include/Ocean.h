#pragma once
#include "common.h"
#include "Cell.h"
#include "Predator.h"
#include "Stone.h"
#include "Prey.h"
#include <vector>
using namespace std;

class Prey;


class Ocean
{
	friend Cell;
	friend Object;
private:
	Cell** cells;
	vector<Object*> stuff;

public:
	Ocean();
	~Ocean();
	void print();
	void addObjects(int, ObjectType);
	void setstuff(Object*);
	void run();
	void deleteObject(Object*);
	Cell* Empty(Pair);
	Cell* Prey1(Pair);
};
