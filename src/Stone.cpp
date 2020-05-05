#include "Stone.h"

Stone::Stone(Cell* cell) : Object(cell) {
	type = ObjType::STONE;
	lifespan = INT_MAX;
	symbol = STONE_N;
	reproduce_time = 0;
}

