//
// Created by aklen on 21.04.2020.
//

#ifndef TASK1_STONE_H
#define TASK1_STONE_H

#include "Ocean.h"
#include "Object.h"
#include "Cell.h"

class Stone: public Object{
public:
    Stone(Cell* cell);
    ~Stone() = default;
    bool live() override;
    char getSymbol() const override;
};
#endif //TASK1_STONE_H
