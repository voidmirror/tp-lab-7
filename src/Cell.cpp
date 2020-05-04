
#include "Cell.h"
#include "Ocean.h"
#include "Object.h"
#include "Stone.h"
#include "Prey.h"
#include "Predator.h"


#include "Additional.h"

Cell::Cell() :
	crd({ 0,0 }), obj(nullptr), ocean(nullptr) {}
Cell::Cell(int x, int y, Ocean* ocean) :
	crd({ x,y }), obj(nullptr), ocean(ocean) {}
Object* Cell::getObject() const {
	return obj;
}

void Cell::init(int x, int y, Ocean* ocean) {
	crd = { x, y };
	this->ocean = ocean;
}

void Cell::setObject(Object* obj) {
	this->obj = obj;
}
void Cell::removeObject() {
	obj = nullptr;
}
Ocean* Cell::getOcean() const {
	return ocean;
}
std::pair<int, int> Cell::getCoordinates() const {
	return crd;
}