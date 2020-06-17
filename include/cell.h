#pragma once
#include "common.h"
#include "object.h"
#include "ocean.h"

class Cell
{
    friend Ocean;
public:
    explicit Cell(Pair p = { 0, 0 }, Ocean* oc = nullptr) :
        crd(p),
        object(nullptr),
        ocean(oc) {}
    void init(Pair p, Ocean* oc);
    Object* getObject() const;
    Ocean* getOcean() const;
    void setObject(Object*);
    void killMe();
    Cell* findEmptyNeighbour();
    Cell* findPreyNeighbour();

private:
    Pair crd;
    Object* object;
    Ocean* ocean;

};