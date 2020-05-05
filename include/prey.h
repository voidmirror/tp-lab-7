//
// Created by Илья on 001 01.05.20.
//

#ifndef TASK1_PREY_H
#define TASK1_PREY_H


#include "object.h"
#include <vector>
using std::vector;


class Prey : public Object {
protected:
    int iterCounter;
public:
    Prey(Cell* cell, char sign);
    ~Prey() override = default;
    bool live() override;
    virtual void reproduce(vector<Cell*>*, int, Object*);
};


#endif //TASK1_PREY_H
