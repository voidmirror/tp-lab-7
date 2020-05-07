#include "Cell.h"

Cell::Cell(Ocean* ocean){
    object = nullptr;
	this->ocean = ocean;
    type = "water";
}

void Cell::live(){
	if (this->type != "water" && this->object != nullptr) {
		this->object->live(*(this->ocean));
	}
}

void Cell::die(){
    this->object = nullptr;
    type = "water";
}