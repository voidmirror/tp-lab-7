#pragma once
#include "common.h"
#include "Object.h"
#include "Ocean.h"

class Ocean;

class Cell
{
	friend Ocean;
	Pair crd;
	Object* object;
	Ocean* ocean;
public:
	Cell();
	Cell(int, int, Ocean*);
	void setObject(Object*);
	Pair getPair();
	Cell* findEmptyCell();
	Cell* findPreyCell();
	Ocean* getOcean();
	Object* getObject();
	void killMe();
};

