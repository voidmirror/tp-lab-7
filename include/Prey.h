#pragma once
#include "LivingObject.h"
#include <vector>
#include <cstring>

class Cell;

class Prey :
        public LivingObject
{
protected:
    int timeToReproduction = 4;
    bool checkCell(Cell* cell) override;
public:
    Prey(Coordinates Coordinates, Ocean* ocean);
    void live() override;
    void eat(Cell* cell) override;
    void reproduct() override;
    std::string getName() override;
};
