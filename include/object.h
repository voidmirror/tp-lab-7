//
// Created by Илья on 001 01.05.20.
//

#ifndef TASK1_OBJECT_H
#define TASK1_OBJECT_H


#include "common.h"

#define STONE_SYMBOL '#'
#define CORAL_SYMBOL '*'
#define PREY_SYMBOL 'f'
#define PREDATOR_SYMBOL 'S'

enum class ObjType {STONE,PREY,PREDATOR};

class Cell;
class Object
{
protected:
    Cell *cell;
    char sign;
public:
    explicit Object(Cell*, char);
    virtual ~Object();
    virtual bool live() = 0;
    void setCell(Cell*);
    Cell* getCell();
    char getSign();
};


#endif //TASK1_OBJECT_H
