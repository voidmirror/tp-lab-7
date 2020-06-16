#ifndef PREY_H
#define PRYE_H

#include "Fish.h"
#include "Ocean.h"

class Cell;

class Prey : public Fish
{
private:
    unsigned int reproductiontime = 8;
    bool direction;
public:
    Prey(Cell* cell);
    ~Prey();
    void live(std::vector< std::vector<Cell*> > cells);
    void reproduction(Cell* cell);
    void go(Cell* cell);
};




#endif