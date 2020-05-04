//
// Created by sdanilov on 4/17/2020.
//

#ifndef TASK1_PREDATOR_H
#define TASK1_PREDATOR_H

#include "ocean.h"
#include "Fish.h"


class Predator: public Fish{
    Cell* self;
public:
    explicit Predator(Cell* current_cell){
        self = current_cell;
		type = "predator";
    };
    void move(Ocean& ocean) override;
    void multiply(Ocean& ocean) override;
};


#endif //TASK1_PREDATOR_H
