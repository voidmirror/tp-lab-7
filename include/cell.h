#ifndef LAB7_CELL_H
#define LAB7_CELL_H

#include <iostream>
#include "common.h"
#include "object.h"
#include "ocean.h"

class Ocean;

class Cell {
    friend Ocean;
private:
    Pair coord;
    Object *object;
    Ocean *ocean;
public:
    Cell();
    void init(int, int, Ocean *);
    Object *getObject();
    void setObject(Object *);
    Ocean *getOcean();
    Cell *emptyCell(Pair coords);
    Cell *preyCell(Pair coords);
    Pair getPair();

};


#endif //LAB7_CELL_H
