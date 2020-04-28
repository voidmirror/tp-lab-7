//
// Created by aklen on 21.04.2020.
//

#ifndef TASK1_OCEAN_H
#define TASK1_OCEAN_H
#include "Common.h"
#include "Cell.h"
#include "Prey.h"
#include "Predator.h"
#include "Stone.h"
#include "Object.h"

using namespace std;

class Cell;
class Object;

class Ocean{
    friend Cell;
private:
    Cell** cells;
    list <Object*> stuff;
    Pair ocean_size;
    int busy_cells_counter;
public:
    Ocean(Pair p);
    ~Ocean();
    void addStuff(Object*);
    void deleteObject(Object*);
    void addObjects(ObjType, int);
    void live(int);
    void print() const;
    Cell* search_empty(Pair coord);
    Cell* search_prey(Pair coord);
};
#endif //TASK1_OCEAN_H
