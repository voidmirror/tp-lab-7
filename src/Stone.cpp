//
// Created by aklen on 23.04.2020.
//
#include "Stone.h"


Stone::Stone(Cell* _cell) :Object(_cell) {
    reproduce_time = 0;
    lifetime = LIFETIME_STONE;
    type = ObjType::STONE;
    symbol = STONE_S;
}

char Stone::getSymbol() const {
    return symbol;
}

bool Stone::live() {
    if(lifetime--)
        return true;
    return false;
}

