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
    void propagate(Ocean& ocean) override;
};


#endif
