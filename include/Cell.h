#pragma once
#include "common.h"
#include "Object.h"


class Ocean;


class Cell
{
	friend Ocean;
private:
	Pair crd;
	Object *obj;
	Ocean *ocean;

public:
	explicit Cell(Pair p = { 0, 0 }, Object* obj = nullptr, Ocean* oc = nullptr) :
		crd(p),
		obj(obj),
		ocean(oc) {	}
	Object* getObject() const;
	char getIcon() const;
	Ocean* getOcean() const;
	Pair getCoord() const;
	void init(Pair p, Ocean* oc);
	void setObject(Object* obj);
	bool isOccupied();
	void killMe();

};