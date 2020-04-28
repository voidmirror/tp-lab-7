//
// Created by Anton Korkunov on 02/04/2020.
//

#ifndef LAB7_CELL_H
#define LAB7_CELL_H

#include "common.h"
#include <string>
#include "Ocean.h"
#include "Object.h"

class Cell{
    friend Ocean;
private:
    Pair crd;
    Object *obj;
    Ocean *ocean;
public:
    explicit Cell(Pair p = { 0, 0 }, Ocean* oc = nullptr) : crd(p), obj(nullptr), ocean(oc) {}
    void init(Pair p, Ocean* oc);
    Object* getObject() const;
    void setObject(Object*);
    void killMe();
    Cell* CheckAround();
    Cell* CheckAround_for_Prey();
    void Call_to_add();
};
#endif //LAB7_CELL_H
