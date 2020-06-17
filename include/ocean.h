//
// Created by Оксана on 19.04.2020.
//

#ifndef TASK1_OCEAN_H
#define TASK1_OCEAN_H

#include "common.h"
#include "cell.h"
#include "object.h"

#include <vector>
#include <string>
using namespace std;



class Ocean{
    friend Cell;
private:
    std::pair<size_t, size_t> sizeOfOcean;
    vector<vector<Cell> > cells;
    vector<Object*> creatures;

public:
    Ocean();
    ~Ocean();
    void addObject(Object* object);
    void addObjects(ObjType type, int amount);
    void print();
    void run(size_t numberOfIterations);
    Cell* getCell(int x, int y);
    bool deleteObject(Cell* cell);
    Cell* getEmptyCellByName(Pair coord);
    Cell* getCellByName(Pair coord, ObjType type);
};





#endif //TASK1_OCEAN_H
