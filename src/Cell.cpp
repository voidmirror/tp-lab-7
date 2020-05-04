//
// Created by sdanilov on 4/14/2020.
//

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

void Cell::kill(){
    this->object = nullptr;
    type = "water";
}