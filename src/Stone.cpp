#include "Stone.h"
#include "Cell.h"
#include "Object.h"

Stone::Stone(Cell* cell) : Object(cell)
{
	lifetime = LTStone;
	type = ObjectType::STONE;
};

bool Stone::live()
{
	if (!lifetime--)
		return false;
	return true;
}