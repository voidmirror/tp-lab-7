//
// Created by Оксана on 19.04.2020.
//

#ifndef TASK1_PREDATOR_H
#define TASK1_PREDATOR_H

#include "Prey.h"

//const int predatorLifetime = 15;
//const int predatorReproducetime = 5;
//const int predatorHungerlevel = 4;

class Predator :public Prey {
protected:
    size_t hungerTimer;
    size_t lifeTimer;
    size_t reproductionTimer;
    bool hunt();
    void reproduce();
    void move();
public:
    Predator(Cell* cell);
    void live()override;
};


#endif //TASK1_PREDATOR_H
