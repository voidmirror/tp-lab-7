#include "stone.h"

Stone::Stone(Cell *c) : Object(c) {
    typeOfObject = ObjType::STONE;
}

bool Stone::live() {
    return true;
}

char Stone::getChar() {
    return '#';
}
