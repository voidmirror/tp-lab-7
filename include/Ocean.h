//
// Created by iddoroshenko on 26.03.2020.
//

#ifndef LAB7_OCEAN_H
#define LAB7_OCEAN_H

#include <list>
#include "Common.h"
#include "Cell.h"

class Object;
class Cell;
class Ocean
{

private:
    int countPrey;
    int countPredator;
    Cell **cells;
    std::list<Object*> stuff;
    std::list<Object*> objects_to_add;
public:
    Ocean();
    ~Ocean();
    void print() const;
    void addObjects(std::list<Object*>& stuff);
    void addObject(Object* stuff);
    void run(int);
    void countPreyChange(int);
    void countPredatorChange(int);
    Cell* getCell(coord_t a, coord_t b);
    int getNumPredators() const;
    int getNumPreys() const;
};

#endif //LAB7_OCEAN_H
