//
// Created by Anton Korkunov on 02/04/2020.
//

#ifndef LAB7_OBJECT_H
#define LAB7_OBJECT_H

#include "common.h"
#include <string>


class Cell;
class Object
{
protected:
    Cell *cell;
public:
    Object();
    virtual ~Object();
    virtual void live() = 0; // жизнь объекта
    virtual std::string type()=0;
    void setCell(Cell*);
    Cell* getCell();
};

#endif //LAB7_OBJECT_H
