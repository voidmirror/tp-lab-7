#pragma once

#include "common.h"
#include "cell.h"
#include "predator.h"
#include "stone.h"
#include "prey.h"
#include <list>

class Ocean
{
    friend Cell;
public:
    Ocean();
    ~Ocean();
    void print(std::ostream&) const;
    void addObjects(ObjType type, unsigned int amount);
    void addStuff(Object* obj);
    void deleteObject(Object* obj);
    void run();
    Cell* findEmpty(Pair crd);
    Cell* findPrey(Pair crd);
private:
    Cell** cells;
    std::list<Object*> stuff;
};