#pragma once
#include "LivingObject.h"

class Cell;

class Predator :
        public LivingObject
{
    int energy = 100;
public:
    Predator(Coordinates Coordinates, Ocean* ocean);
    void eat(Cell* cell) override;
    void reproduct() override;
    std::string getName() override;
    Cell* findFood();
    static bool isFood(Cell* cell);

    void live() override;
    bool checkCell(Cell* cell) override;
};