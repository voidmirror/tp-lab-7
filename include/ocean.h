//
// Created by Илья Соловьёв on 05.05.2020.
//

#ifndef TASK1_OCEAN_H
#define TASK1_OCEAN_H

#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include "stone.h"
#include "prey.h"
#include "predator.h"

class Ocean{
    friend Cell;
private:
    std::pair<size_t, size_t> sizeOfOcean;
    std::vector<std::vector<Cell*>> cells;
    std::list<Object*> creatures;

public:
    Ocean(int size_x, int size_y);
    void print();
    void addCreature(Object* obj);
    void addCreatures(ObjType type, size_t number);
    void live(size_t numberOfIterations);
    Cell* isPreyAround(std::pair<size_t, size_t> coords);
    Cell* isFreeCellAround(std::pair<size_t, size_t> coords);
};
#endif //TASK1_OCEAN_H
