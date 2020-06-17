#ifndef LAB7_OCEAN_H
#define LAB7_OCEAN_H

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "cell.h"
#include "object.h"
#include "prey.h"
#include "predator.h"
#include "stone.h"
using namespace std;

class Ocean{
    friend Cell;
private:
    Pair oceanSize;
    list<Object*> stuff;
    vector<vector<Cell*>> cells;
public:
    Ocean(int, int);
    void print();
    void addStuff(Object*);
    void addObjects(ObjType type, int num);
    void live(int numOfIter);
    Cell* emptyCell(Pair coords);
    Cell* preyCell(Pair coords);
};

#endif //LAB7_OCEAN_H
