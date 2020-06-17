//
// Created by artem on 06.05.2020.
//

#ifndef OCEANEMULATOR_PREDATOR_H
#define OCEANEMULATOR_PREDATOR_H

#include "Object.h"

class Cell;

class Coordinates;

class Predator : public Object {

private:

    bool readyToGiveBirth = false;
    int timeToDie = 10;

public:
    Predator(Cell *cell, Coordinates coordinates, OceanType oceanType);

    void live() override;
};


#endif //OCEANEMULATOR_PREDATOR_H
