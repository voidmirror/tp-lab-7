#pragma once

#include "Object.h"

class Stone : public Object {
public:
    Stone(Cell* cell) : Object{cell} { type = ObjType::STONE; };
    ~Stone() = default;
    bool live() override { return true; };
};