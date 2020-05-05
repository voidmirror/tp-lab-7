//
// Created by Илья on 001 01.05.20.
//

#ifndef TASK1_STONE_H
#define TASK1_STONE_H


#include "cell.h"

class Stone : public Object {
public:
    explicit Stone(Cell*, char);
    bool live() override{ return true; };
};


#endif //TASK1_STONE_H
