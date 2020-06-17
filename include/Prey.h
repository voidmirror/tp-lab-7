#ifndef PREY_H
#define PREY_H


#include "Object.h"
#include "Cell.h"
#include "Ocean.h"
#include "common.h"
#include "Fish.h"

class Cell;
class Ocean;
class Prey : public Fish
{
public:
    Prey(Cell* cell);
    bool live();
    void move();
    void reproduce();
};


#endif
