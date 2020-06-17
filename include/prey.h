#pragma once
#include "object.h"
#include "cell.h"
#include "ocean.h"
#include "common.h"

class Cell;
class Ocean;
class Prey : public Object
{
public:
    Prey(Cell* cell);
    bool live() override;
    char getChar() override;
    void move() override;
    void reproduce() override;
};