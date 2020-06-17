#ifndef CELL_H
#define CELL_H

#include <vector>
#include "common.h"
#include "Object.h"

class Ocean;

class Cell
{
	friend Ocean;
private:
	Pair crd;
	Object* obj;
	Ocean* ocean;
public:
	explicit Cell(Pair p = { 0, 0 }, Ocean* oc = nullptr);
	void init(Pair p, Ocean* oc);
	void setObject(Object* obj);
	Object* getObject() const;
	Pair getCrd() const;
	Ocean* getOcean() const;
};


#endif