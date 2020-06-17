#include "Cell.h"
#include "Object.h"
#include "Ocean.h"

void Cell::init(Pair p, Ocean* oc) {
	coord = p;
	ocean = oc;
	obj = nullptr;
}

void Cell::setObject(Object* object) {
	obj = object;
}

Object* Cell::getObj() const {
	return obj;
}

void Cell::killme() {
	if (obj) {
		delete obj;
		obj = nullptr;
	}
}

Cell* Cell::findCellToMove() const {
	return ocean->EmptyCellAroundIt(coord);
		
}

Cell* Cell::findCellToEat() const {
	return ocean->CellWithPreyAroundIt(coord);
}

Ocean* Cell::getOcean() const {
	return ocean;
}