#pragma once

#include "common.h"

class Ocean;
class Object;

class Cell {
private:
	Pair crd;
	Object* obj;
	Ocean* ocean;
public:
	Cell(Pair p = { 0, 0 }, Ocean* oc = nullptr);
	void init(Pair p, Ocean* oc);
	void setObject(Object*);
	Object* getObject() const;
	Pair getCoord() const;
};
