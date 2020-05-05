#include "Stone.hpp"
#include "Defaults.h"

Stone::Stone(Cell *cell) : Object(cell) {
    lifetime = STONE_LIFE;
    type = ObjType::STONE;
}

char Stone::getChar() {
    return STONE_CHAR;
}

bool Stone::live() {
    return true;
}
