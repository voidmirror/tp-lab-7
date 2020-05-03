#include "Cell.h"

void Cell::init(Pair coord, Ocean* ocean) {
	this->coord = coord;
	this->ocean = ocean;
}

Object* Cell::get_object() {
	return obj;
}

Ocean* Cell::get_ocean() {
	return ocean;
}

Pair Cell::get_coord() {
	return coord;
}
void Cell::set_object(Object* obj) {
	this->obj = obj;
}

void Cell::clear_cell() {
	obj = nullptr;
}
