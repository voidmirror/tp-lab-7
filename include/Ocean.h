#ifndef _OCEAN_H
#define _OCEAN_H

#include <vector>
#include <iostream>
#include <iterator>

#include "Object.h"
#include "Cell.h"


class Ocean
{
private:
    size_t size_x;
    size_t size_y;
    std::vector< std::vector<Cell*> > cells;
    std::vector<Object*> objects;
public:
    Ocean(size_t size_x, size_t size_y);
    ~Ocean();
    void spawnObjects();
    void move();
    void print();
    void run();
    void addObject(Object* obj);
    Cell* getCell(size_t x, size_t y);
    bool isDieOut();
};

#endif