#pragma once
#include "LivingObject.h"
#include <vector>
#include <cstring>

class Cell;

class Prey :
        public LivingObject
{
protected:
    int daysBeforeBreeding = 5;
    bool checkCell(Cell* cell);
public:
    Prey(int x, int y, Ocean* ocean);
    Prey(coord Coordinates, Ocean* ocean);
    void live();
    void eat(Cell* cell);
    void multiply();
    std::string getName();
};
