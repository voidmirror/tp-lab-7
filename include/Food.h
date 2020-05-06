//
// Created by artem on 05.04.2020.
//

#ifndef OCEANEMULATOR_FOOD_H
#define OCEANEMULATOR_FOOD_H


#include "Object.h"

class Food : public Object {
public:
    Food(Cell *cell, Coordinates coordinates, OceanType oceanType);

    void live() override;
};


#endif //OCEANEMULATOR_FOOD_H
