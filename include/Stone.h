#ifndef STONE_H
#define STONE_H

#include "Object.h"

class Cell;
class Ocean;

class Stone : public Object 
{
private:

public:
    Stone(Cell* cell);
    ~Stone();
    void live(std::vector< std::vector<Cell*> > cells);
};

#endif