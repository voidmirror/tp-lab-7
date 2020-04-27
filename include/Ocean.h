//
// Created by fiskirton on 08.04.2020.
//

#ifndef OCEAN_OCEAN_H
#define OCEAN_OCEAN_H

#include "config.h"
#include "Cell.h"
#include "ObjectCreator.h"
#include <vector>
#include <map>
#include <string>

using namespace std;

class Ocean {

private:
    Cell **cells;
    vector<Object* > objects;
    vector<Object* > deadObj;
    vector<Object* > newObj;

private:
    map<int, ObjectCreator *> creators;

private:
    void makeGrid();
    void fillMap();
    void printMap();
    void addCreator(int type, ObjectCreator *creator);

public:
    void init();
    void removeObj(Object *object);
    void flushOld();
    void flushNew();
    void addDead(Object *object);
    void addNew(Object *object);

    ObjectCreator *getCreator(int type_id);

public:
    Cell **getCells() const;
};


#endif //OCEAN_OCEAN_H
