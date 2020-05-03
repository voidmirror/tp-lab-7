#include "Stone.h"

Stone::Stone(Cell* c) :Object(c)
{
	life = life_span_stone;
	species = ObjType::STONE;
	symb = STONE_N;
	alive = true;
}

void Stone::live()
{
	life--;
	if (life < 0)
		alive = false;
}