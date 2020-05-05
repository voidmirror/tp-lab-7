//
// Created by Илья on 001 01.05.20.
//

#ifndef TASK1_PREDATOR_H
#define TASK1_PREDATOR_H


#include "prey.h"

class Predator : public Prey {
protected:
    int itersSinceEating;
public:
    Predator(Cell* cell, char sign);
    ~Predator() override = default;
    bool live() override;
    void hunt();
};

#endif //TASK1_PREDATOR_H
