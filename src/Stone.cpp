#include "Stone.h"

Stone::Stone(Cell* cell) : Object(cell) {
	this->type = ObjectType::STONE;
}

void Stone::live() {}
