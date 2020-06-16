#pragma once
#include "common.h"
#include "Ocean.h"
#include "Object.h"

class Ocean;

class Cell
{
	friend Ocean;
	friend Object;
private:
	Pair crd;
	Object* object;
	Ocean* ocean;
public:
	explicit Cell(Pair p = { 0, 0 }, Ocean* oc = nullptr) :
		crd(p),
		object(nullptr),
		ocean(oc) {}
	void init(Pair p, Ocean* oc);
	Object* getObject();
	void setObject(Object*);
	void killMe();
	Ocean* getOcean();
	Cell* findEmpty();
	Cell* findPrey();
};
