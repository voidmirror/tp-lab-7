#pragma once

#include "Object.h"
#include "common.h"


class Ocean;

class Cell {
    friend Ocean;
private:
    Pair crd;
    Object* obj;
    Ocean *ocean;
public:
    explicit Cell(Pair p = { 0, 0 }, Ocean* oc = nullptr) :
            crd{p},
            obj{nullptr},
            ocean{oc} {}
    void init(Pair p, Ocean* oc);
    void setObject(Object* object);
    void killMe();

    bool isEmpty() const;
    Object* getObj() const;
    Ocean* getOcean() const;
    Cell* findEmptyCell() const;
    Cell* findType(ObjType type) const;
};

