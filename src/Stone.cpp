#include "Stone.h"

Stone::Stone(Cell* cell_) : Object(cell_) 
{
	spawn_time = 0;
	days_of_life;
	type = ObjType::STONE;
	symbol = STONE_N;
}

bool Stone::live() 
{
	return true;
}
