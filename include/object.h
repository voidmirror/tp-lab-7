#ifndef LAB7_OBJECT_H
#define LAB7_OBJECT_H

#include "common.h"

class Cell;

enum ObjType {
    PREY, PREDATOR, STONE, NONE
};

class Object {
protected:
    Cell *cell;
    ObjType typeOfObject;
public:
    explicit Object(Cell *newCell = nullptr);
    virtual ~Object() = default;
    ObjType getObjType();
    Cell *getCell();
    void setCell(Cell *);
    virtual bool live() = 0;
    virtual char getChar() = 0;
};

#endif //LAB7_OBJECT_H
