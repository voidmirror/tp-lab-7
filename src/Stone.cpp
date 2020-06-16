#include "Stone.h"

Stone::Stone(Cell* cell, ObjType type) : Object(cell, type)
{
	
}

bool Stone::live()
{
	return true;
}

char Stone::getChar()
{
	return '.';
}