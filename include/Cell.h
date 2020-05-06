#pragma once
#include "common.h"
#include "Object.h"

class Ocean;

class Cell{
	friend Ocean;
private:
	Pair crd;
	Object *obj;
	Ocean *ocean;
public:
	Cell();
	void init(Pair p, Ocean* oc);
	Object* getObject();
	Pair getCoord();
	Ocean* getOcean();
	void setObject(Object*);
	void killMe();
};
