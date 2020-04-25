#ifndef PREDATOR_H
#define PREDATOR_H

#include "Fish.h"
#include "Ocean.h"

class Cell;
class Ocean;

class Predator : public Fish
{
private:
    bool full;
public:
    Predator(Cell* cell);
    ~Predator();
    void live(std::vector< std::vector<Cell*> > cells);
    void reproduction(Cell* cell);
    void kill(Cell* cell);
};

#endif