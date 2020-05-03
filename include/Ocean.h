#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <thread>

#include "common.h"
#include "Cell.h"
#include "Object.h"
#include "Stone.h"
#include "Prey.h"
#include "Predator.h"

class Ocean
{
	friend Cell;
	Cell** cells;
	std::list<Object*> stuff;

public:
	Ocean();
	void addObjects(ObjType, int);
	void print();
	void addStuff(Object*);
	void deleteObject(Object*);
	Cell* findEmpty(Cell*);
	Cell* findPrey(Cell*);
	void run(int);
	void run();
};

