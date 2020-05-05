//
// Created by Оксана on 19.04.2020.
//

#ifndef TASK1_STONE_H
#define TASK1_STONE_H
#include "object.h"

class Stone :public Object {
public:
    Stone(Cell* cell);
    void live()override ;
    void die()override;
};
#endif //TASK1_STONE_H
