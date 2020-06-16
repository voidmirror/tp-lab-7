//
// Created by sdanilov on 4/14/2020.
//

#ifndef TASK1_STONE_H
#define TASK1_STONE_H

#include "Object.h"
#include "Cell.h"

class Stone: public Object{
public:
    Cell* self;
public:
    explicit Stone(Cell* current_cell){
        self = current_cell;
		type = "stone";
    }
    void live(Ocean& ocean) override{}
};


#endif //TASK1_STONE_H
