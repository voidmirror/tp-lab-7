//
// Created by Mikhail on 01.05.2020.
//

#ifndef TASK1_PREDATOR_H
#define TASK1_PREDATOR_H

#include <prey.h>

class Predator: public Prey {
private:
    ObjType type = ObjType::PREDATOR;
    int eatTime;
public:
    explicit Predator(Cell*);
    bool live() override;
    void eat();
    void reproduce() override;
    ObjType getType() override;
};
#endif //TASK1_PREDATOR_H
