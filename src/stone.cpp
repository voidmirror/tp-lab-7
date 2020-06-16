//
// Created by Mikhail on 01.05.2020.
//
#include <stone.h>

bool Stone::live() {
    return true;
}

ObjType Stone::getType() {
    return type;
}

Stone::Stone(Cell * _cell) : Object(_cell) {}
