//
// Created by Оксана on 04.05.2020.
//

#ifndef TASK1_OBJECT_H
#define TASK1_OBJECT_H

#include "common.h"
//#include "cell.h"

#define STONE_N '#'
#define CORAL_H '*'
#define PREY_N 'f'
#define PREDATOR_N 'S'

enum class ObjType {STONE, PREY, PREDATOR, NONE};

class Cell;

class Object
{
protected:
    ObjType type = ObjType::NONE;
    Cell* cell;
    char symb;
public:
    Object(Cell* = nullptr);
    ~Object();
    virtual void live() = 0;
    virtual void die() = 0;
    void setCell(Cell* cell);
    ObjType getObjectType() const;
    Cell* getCell() const;
    char getSymb();
    //bool isAlive();
    //?virtual void die();
};




#endif //TASK1_OBJECT_H
