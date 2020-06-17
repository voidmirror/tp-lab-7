//
// Created by Илья on 001 01.05.20.
//

#ifndef TASK1_OCEAN_H
#define TASK1_OCEAN_H


#include "common.h"
#include "cell.h"
#include <list>
#include <vector>
using std::vector;


class Ocean
{

private:
    vector<vector<Cell*>> cells;
    std::list<Object*> stuff;
    std::list<Object*> toDelete;
    void counter(size_t&, size_t&, size_t&);
    friend Cell;
public:
    Ocean();
    ~Ocean();
    void print() const;
    void addObjects(ObjType type, size_t number);
    void run();
    vector<Cell*>* getEmptyCells(Cell*);
    void addObject(Object*);
    vector<Cell*>* getCellsWithPrey(Cell*);
    void killObject(Cell*);
};


#endif //TASK1_OCEAN_H
