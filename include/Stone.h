//
// Created by artem on 05.04.2020.
//

#ifndef OCEANEMULATOR_STONE_H
#define OCEANEMULATOR_STONE_H


#include "Object.h"

class Stone: public Object {
public:
    Stone(Cell* cell, Coordinates coordinates, OceanType oceanType);

    void live() override;
};


#endif //OCEANEMULATOR_STONE_H
