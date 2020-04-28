//
// Created by aklen on 21.04.2020.
//

#ifndef TASK1_PREY_H
#define TASK1_PREY_H
#include "Object.h"
#include "Ocean.h"
#include "Cell.h"


class Prey:public Object{
private:
public:
    Prey(Cell* cell);
    bool live() override ;
    char getSymbol() const override ;
    void move();
    void reproduce();
};
#endif //TASK1_PREY_H
