#include "Stone.h"
#define STONE '#'

Stone::Stone(int x, int y, Ocean* ocean): Object(x, y, ocean)
{
	symbol = STONE;
}

Stone::Stone(coord coordinates, Ocean* ocean) : Object(coordinates, ocean) {
	symbol = STONE;
}


std::string Stone::getName() { return "Stone"; }