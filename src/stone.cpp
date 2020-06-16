#include "stone.h"


Stone::Stone(Cell* cell) : Object(cell) {}


char Stone::getName() {
	return name;
}


void Stone::live()
{}

