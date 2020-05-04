//
// Created by iddoroshenko on 26.03.2020.
//

#ifndef LAB7_CELL_H
#define LAB7_CELL_H

#include "Common.h"
#include "Object.h"

class Ocean;
class Object;
class Cell
{
    friend Ocean;
private:
    Pair crd;
    Object *obj;
    Ocean *ocean;
public:
    explicit Cell(Pair p = { 0, 0 }, Ocean* oc = nullptr)
            : crd(p), obj(nullptr), ocean(oc) {}
    void init(Pair p, Ocean* oc);
    Object* getObject() const;
    void setObject(Object*);
    void killMe();
    Pair getCrd() const;
    Ocean* getOcean();
};
#endif //LAB7_CELL_H
