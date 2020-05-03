//
// Created by Ignatovskiy Nikita on 28.04.2020.
//

#ifndef LAB7_PREDATOR_H
#define LAB7_PREDATOR_H


#include "cell.h"


class Predator : public Object
{

private:

    bool hungerLevel = false;

public:

    Predator(Cell* cell);

    bool live() override;
    char getSymbol() override;
    void move() override;
    void reproduce() override;
    bool eat();

};


#endif //LAB7_PREDATOR_H
