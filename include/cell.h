//
// Created by Илья on 001 01.05.20.
//

#ifndef TASK1_CELL_H
#define TASK1_CELL_H


#include "common.h"
#include "object.h"
#include <vector>
using std::vector;

class Ocean;

class Cell
{
    friend Ocean;
private:
    Pair crd;
    Object *obj;
    Ocean *ocean;
public:
    explicit Cell(Pair p, Ocean* oc) :
            crd(p),
            obj(nullptr),
            ocean(oc) {};
    Pair getCrd();
    Object* getObject() const;
    void setObject(Object*);
    void killMe();
    vector<Cell*>* getEmptyCells();
    void addToOcean(Object*);
    vector<Cell*>*  getPreyCells();
};


#endif //TASK1_CELL_H
