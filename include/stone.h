#pragma once
#include "object.h"
#include "cell.h"
#include "ocean.h"
#include "common.h"

class Stone : public Object
{

public:
    Stone(Cell* cell);
    ~Stone() = default;
    bool live() override;
    char getChar() override;
};