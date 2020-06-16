#pragma once
#ifndef _CELL_H_
#define _CELL_H_


#include "object.h"

class Ocean;
class Cell {
	friend Ocean;
private:
	Pair coord;
	Object* obj;
	Ocean* ocean;
public:
	explicit Cell(Pair p = { 0, 0 }, Ocean* oc = nullptr) :
		coord(p),
		obj(nullptr),
		ocean(oc) {}
	void init(Pair, Ocean*);
	Object* getObject();
	Ocean* getOcean();
	void setObject(Object*);
	void clearCell();
	Pair getCoord();
};
#endif