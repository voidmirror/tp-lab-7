//
// Created by sdanilov on 4/14/2020.
//

#include "ObjectManufacture.h"
#include "Object.h"
#include "Stone.h"
#include "Pray.h"
#include "Predator.h"
#include <time.h>

Object* ObjectManufacture::newObject(const string& type, Cell* cell){
	cell->type = type;
    if (type == "stone"){
        return new Stone(cell);
    }
    if (type == "prey"){
        return new Prey(cell);
    }
    if (type == "predator"){
        return new Predator(cell);
    }
}

Object* ObjectManufacture::newRandomObject(Cell* cell) {
	int coin = rand() % 100;
	if (coin < 1) {
		return ObjectManufacture::newObject("predator", cell);
	}
	else if (coin < 20) {
		return ObjectManufacture::newObject("prey", cell);
	}
	else if (coin < 40) {
		return ObjectManufacture::newObject("stone", cell);
	}
	return nullptr;
}