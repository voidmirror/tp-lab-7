//
// Created by Mary on 15.04.2020.
//

#ifndef TASK1_PREY_H
#define TASK1_PREY_H
#include <cstdlib>
#include "object.h"

class Cell;
class Prey: public Object{
protected:
    int lifeTime;
    int reproductiveTime;
public:
    explicit Prey(Cell* c);

    bool live() override;
    void kill();
    char getSymbol() override;
    virtual void reproduce();
    virtual void move();
};
#endif //TASK1_PREY_H
