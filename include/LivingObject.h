#pragma once
#include "Object.h"
#include <vector>

enum Directions { UP, RIGHT, DOWN, LEFT };

class Cell;

class LivingObject :
        public Object
{
protected:
    void move(int x, int y);
    void motion();
    virtual bool checkCell(Cell* cellTo) = 0;
    std::vector<Cell*> getNeighbouredCells();
public:
    virtual void live() = 0;
    virtual void eat(Cell* cell) = 0;
    void birth();
    void die();
    virtual void reproduct() = 0;
    LivingObject(int x, int y,  Ocean* ocean);
    LivingObject(Coordinates coordinates, Ocean* ocean);
};