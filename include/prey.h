//
// Created by Оксана on 19.04.2020.
//

#ifndef TASK1_PREY_H
#define TASK1_PREY_H

#include "object.h"

//const int preyLifetime = 10;
//const int preyReproducetime = 5;

class Prey :public Object {
protected:
    size_t lifeTimer;
    size_t reproductionTimer;

    virtual void move();

    virtual void reproduce();
public:
    Prey(Cell* cell);
    void live() override;
    void die() override;
};




#endif //TASK1_PREY_H
