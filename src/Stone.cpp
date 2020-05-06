#include "Stone.h"


Stone::Stone(Coordinates coordinates, Ocean *ocean) : Object(coordinates, ocean) {
    character = '0';
}

std::string Stone::getName() {
    return "Stone";
}