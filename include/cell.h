#pragma once
#include "common.h"
#include "ocean.h"
#include "object.h"

class Ocean;

class Cell
{
	friend Ocean;
private:
	Pair coordinates;
	Object* object;
	Ocean* ocean;
public:
	explicit Cell(Pair p = { 0, 0 }, Ocean* oc = nullptr) :
		coordinates(p),
		object(nullptr),
		ocean(oc) {}
	void init(Pair p, Ocean* oc);
	Object* getObject();
	void setObject(Object* obj);
	void killMe();
	Pair getCoordinates();
	Ocean* getOcean();
};