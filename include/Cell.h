//
// Created by aklen on 21.04.2020.
//

#ifndef TASK1_CELL_H
#define TASK1_CELL_H
#include "Common.h"
#include "Object.h"
#include "Ocean.h"

class Cell{
    friend Ocean;
    friend Object;

private:
    Pair coord;
    Object* obj = nullptr;
    Ocean* ocean;

public:
    explicit Cell(Pair p = { 0, 0 }, Ocean* oc = nullptr):
                coord(p),
                ocean(oc){}
    void setObject(Object*);
    void initObj(Pair p,  Ocean* oc );
    void kill();
    Object* getObject();
    Ocean* getOcean();
    Cell* search_empty();
    Cell* search_prey();

};
#endif //TASK1_CELL_H
