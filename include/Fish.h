#ifndef FISH_H
#define FISH_H

#include "Object.h"

class Fish: public Object
{
protected:
    unsigned int maxlivetime;
    unsigned int livetime;
    bool direction;
public:
    Fish(unsigned int mintime, Cell* cell);
    ~Fish();
    virtual void reproduction(Cell* cell) = 0;
};

#endif