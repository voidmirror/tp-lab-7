#pragma once
#include "object.h"
#include "cell.h"
#include "ocean.h"
#include "common.h"

class Predator : public Object
{
public:
    Predator(Cell* cell);
    bool live() override;
    char getChar() override;
    bool eat();
    void move() override;
    void reproduce() override;

private:
    bool fed = false;
};
