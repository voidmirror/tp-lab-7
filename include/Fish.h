#ifndef FISH_H
#define FISH_H

#include "Object.h"
#include "Cell.h"
#include "Ocean.h"
#include "common.h"

class Cell;
class Ocean;
class Fish : public Object
{
protected:
    Fish(Cell* cell);
public:
    void move();
    virtual void reproduce() = 0;
};

#endif // FISH_H
