#include "Factory.h"
#include "Object.h"
#include "Stone.h"
#include "Pray.h"
#include "Predator.h"
#include <time.h>

Object* Factory::newObject(const string& type, Cell* cell){
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

Object* Factory::newRandomObject(Cell* cell) {
	int coin = rand() % 100;
	if (coin < 1) {
		return Factory::newObject("predator", cell);
	}
	else if (coin < 20) {
		return Factory::newObject("prey", cell);
	}
	else if (coin < 40) {
		return Factory::newObject("stone", cell);
	}
	return nullptr;
}