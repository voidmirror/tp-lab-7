//
// Created by Ignatovskiy Nikita on 28.04.2020.
//


#include "stone.h"


Stone::Stone(Cell *cell) : Object(cell)
{
    lifetime = LIFETIME_STONE;
    type = ObjType::STONE;
}


char Stone::getSymbol()
{
    return STONE_N;
}


bool Stone::live()
{
    return (lifetime--) > 0;
}