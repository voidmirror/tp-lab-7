//
// Created by iddoroshenko on 28.04.2020.
//

#ifndef LAB7_PREDATOR_H
#define LAB7_PREDATOR_H

#include "Prey.h"
class Prey;
class Predator : public Prey {
protected:
    int hungry;
    bool eat();
public:
    Predator() : Prey(ObjType::PREDATOR, PREDATOR_LIVE_TIME), hungry(PREDATOR_DEFAULT_HUNGRY_TIME) {}
    void live() override;
};
#endif //LAB7_PREDATOR_H
