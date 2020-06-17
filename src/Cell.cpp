#include "Cell.h"
#include "Ocean.h"

Cell::Cell() : coordinates({0, 0}), object(nullptr), ocean(nullptr){
}

Pair Cell::getCoordinates() {
	return coordinates;
}

void Cell::setCoordinates(Pair coordinates) {
	this->coordinates = coordinates;
}

Object* Cell::getObject() {
	return object;
}

void Cell::setObject(Object* object) {
	this->object = object;
}

Ocean* Cell::getOcean() {
	return ocean;
}

void Cell::create(Pair coordinates, Ocean* ocean)  {
	this->coordinates = coordinates;
	this->ocean = ocean;
}

void Cell::deleteItem() {
	ocean->deleteObject(this->object);
	delete object;
	this->object = nullptr;
}