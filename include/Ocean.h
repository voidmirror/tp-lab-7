//
// Created by fiskirton on 08.04.2020.
//

#ifndef OCEAN_OCEAN_H
#define OCEAN_OCEAN_H

#include <vector>
#include <map>
#include <string>

#include "config.h"
#include "Cell.h"
#include "ObjectCreator.h"

using namespace std;

class Ocean {

    friend class Animate;


private:
    Cell **cells;
    vector<Object* > objects;
    vector<Object* > deadObj;
    vector<Object* > newObj;
    map<int, int> population;

private:
    map<int, ObjectCreator *> creators;

private:
    void makeGrid();
    void fillMap();
    void printMap();
    void addCreator(int type, ObjectCreator *creator);
    void flushOld();
    void flushNew();

private:
    void removeObj(Object *object);
    void addDead(Object *object);
    void addNew(Object *object);


public:
    void init();

public:
    ObjectCreator *getCreator(int type_id);
    Cell **getCells() const;

    map<int, int> & getPopulation() ;
};


#endif //OCEAN_OCEAN_H
