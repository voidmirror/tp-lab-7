#include "Object.h" //fix

Object::Object(Cell* cell) {
	this->cell = cell;
};

void Object::SetLifetime(unsigned int newlifetime) {
	this->lifetime = newlifetime;
};

unsigned int Object::GetLifetime() {
	return lifetime;
};

void Object::SetCell(Cell* newcell) {
	this->cell = newcell;
};

Cell* Object::GetCell() {
	return cell;
};

bool Object::IsLive() {
	return dead;
};

void Object::Die() {
	this->dead = true;
};

ObjectType Object::GetType() {
	return type;
};