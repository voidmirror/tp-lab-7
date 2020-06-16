//
// Created by Ignatovskiy Nikita on 28.04.2020.
//

#ifndef LAB7_CELL_H
#define LAB7_CELL_H


#include "object.h"
#include "ocean.h"


class Cell
{
    friend Ocean;

private:

    Pair crd;
    Object *object;
    Ocean *ocean;

public:

    explicit Cell(Pair p = { 0, 0 }, Ocean* oc = nullptr) :
            crd(p),
            object(nullptr),
            ocean(oc) {}

    void initialize(Pair pair_, Ocean* ocean_);
    Object* getObject();
    Ocean* getOcean();

    void setObject(Object*);
    void kill();

    Cell* getNearFreeCell();
    Cell* getPreyAround();

};


#endif //LAB7_CELL_H
