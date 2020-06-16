//
// Created by aklen on 21.04.2020.
//

#ifndef TASK1_OBJECT_H
#define TASK1_OBJECT_H
#include "Common.h"

enum class ObjType{PREY, PREDATOR, STONE};


class Cell;
class Ocean;


class Object{
    friend Ocean;
    friend Cell;

protected:
    Cell* cell;
    ObjType type;
    char symbol;
    int lifetime;
    int reproduce_time;


public:
    Object(Cell* = nullptr);
    virtual ~Object() = default;
    void setCell(Cell*);
    Cell* getCell();
    ObjType getType();
    virtual bool live() = 0;
    virtual char getSymbol() const = 0;
    void set_lifetime(int);
};


#endif //TASK1_OBJECT_H
