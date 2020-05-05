#pragma once

#include "Object.h"
#include "Common.h"

class Ocean;

class Cell {
	friend Ocean;
private:
	Pair coord;
	Object* obj;
	Ocean *ocean;
public:
	explicit Cell(Pair p = { 0, 0 }, Ocean* oc = nullptr) :
		coord(p),
		obj(nullptr),
		ocean(oc) {}
	void init(Pair p, Ocean* oc);
	void setObject(Object* object);
	void killme();
	Object* getObj() const;
	Cell* findCellToMove() const;
	Cell* findCellToEat() const;
	Ocean* getOcean() const;
};