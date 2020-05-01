#include "Cell.h" //fix

void Cell::Init(Pair p, Ocean* oc) {
	cords = p;
	ocean = oc;
};

Object* Cell::GetObject() {
	if (obj)
		return obj;
	else
		return nullptr;
};

void Cell::SetObject(Object* newobj) {
	this->obj = newobj;
};

void Cell::KillMe() {
	if (obj) {
		delete obj;
		this->obj = nullptr;
	}
};

Ocean* Cell::GetOcean() {
	return this->ocean;
};

Cell* Cell::FindEmptyNeighbour() {
	return ocean->FindEmptyCell(cords);
};

Cell* Cell::FindPreyNeighbour() {
	return ocean->FindPreyCell(cords);
};

Pair Cell::Cords() {
	return this->cords;
};

void Cell::Move() {
	obj->SetCell(nullptr);
	obj = nullptr;
};