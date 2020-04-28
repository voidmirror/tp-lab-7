//
// Created by aklen on 21.04.2020.
//

#ifndef TASK1_PREDATOR_H
#define TASK1_PREDATOR_H
#include "Cell.h"
#include "Ocean.h"
#include "Object.h"

class Predator: public Object{

private:
    int eat_time;
public:
    Predator(Cell *cell);
    bool live() override ;
    char getSymbol() const  override ;
    bool eat();
    void move();
    void reproduce();

};
#endif //TASK1_PREDATOR_H
