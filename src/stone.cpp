#include "stone.h"

Stone::Stone(Cell* cell) : Object(cell)
{
	type = ObjType::STONE;
};

void Stone::live()
{
	return;
}