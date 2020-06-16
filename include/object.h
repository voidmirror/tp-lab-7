//
// Created by Mary on 15.04.2020.
//

#ifndef TASK1_OBJECT_H
#define TASK1_OBJECT_H
#include "common.h"
class Cell;
enum ObjType {
    STONE,
    PREY,
    PREDATOR,
    NONE
};
class Object{
protected:
    Cell* cell;
    ObjType typeOfObject;
public:
    explicit Object(Cell *c = nullptr);
    virtual ~Object() = default;
    ObjType getTypeOfObject();
    Cell* getCell();
    void setCell(Cell* newCell);
    virtual bool live() = 0;
    virtual char getSymbol() = 0;
};
#endif //TASK1_OBJECT_H

