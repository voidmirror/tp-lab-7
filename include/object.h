//
// Created by Mikhail on 01.05.2020.
//

#ifndef TASK1_OBJECT_H
#define TASK1_OBJECT_H

#include <helpers.h>

class Cell;

class Object {
protected:
    Cell* cell;
    ObjType type = ObjType::NONE;
public:
    Object(Cell* _cell);
    void setCell(Cell* _cell);
    Cell* getCell();
    virtual bool live();
    virtual ObjType getType();
    virtual ~Object()= default;
};
#endif //TASK1_OBJECT_H
