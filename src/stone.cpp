#include "stone.h"
#include "cell.h"
#include "object.h"

Stone::Stone(Cell* cell) : Object(cell)
{
    lifetime = LT_Stone;
    type = ObjType::STONE;
};

char Stone::getChar()
{
    return STONE_N;
}

bool Stone::live()
{
    if (!lifetime--)
        return false;
    return true;
}