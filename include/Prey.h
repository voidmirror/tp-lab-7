//
// Created by artem on 05.04.2020.
//

#ifndef OCEANEMULATOR_PREY_H
#define OCEANEMULATOR_PREY_H


#include "Object.h"

class Prey : public Object {
private:

    bool readyToGiveBirth = false;

public:
    Prey(Cell *cell, Coordinates coordinates, OceanType oceanType);

    void live() override;
};


#endif //OCEANEMULATOR_PREY_H
