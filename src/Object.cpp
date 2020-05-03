#include "Object.h"

Object::Object(Cell* cell) {
	this->cell = cell;
};

void Object::set_cell(Cell* cell) {
	this->cell = cell;
}

Cell* Object::get_cell() {
	return cell;
}

ObjectType Object::get_type() {
	return type;
};