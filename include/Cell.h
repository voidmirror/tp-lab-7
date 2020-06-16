#ifndef _CELL_H_
#define _CELL_H_

#include "Object.h"
#include "Ocean.h"

class Cell
{
	friend Ocean;
private:
	Pair crd;
	Object* obj;
	Ocean* ocean;
public:
	explicit Cell(Pair p = { 0, 0 }, Ocean* oc = nullptr) :
		crd(p),
		obj(nullptr),
		ocean(oc) {}
	void init(Pair p, Ocean* oc);
	Object* getObject() const;
	void setObject(Object*);
	Pair getCrd();
	Cell* findEmptyCellNear();
	Cell* findFoodNear();
	Ocean* getOcean();
	void killMe();
};
#endif