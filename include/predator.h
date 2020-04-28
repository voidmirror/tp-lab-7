//
// Created by Mary on 15.04.2020.
//

#ifndef TASK1_PREDATOR_H
#define TASK1_PREDATOR_H
#include "prey.h"
class Cell;
class Predator: public Prey{
private:
    int famineTime;
public:
    explicit Predator(Cell* c);

    bool live() override;

    char getSymbol() override;

    void move() override ;
    void reproduce() override;

    void eat(Prey* prey);

};
#endif //TASK1_PREDATOR_H
