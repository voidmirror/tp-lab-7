//
// Created by Ignatovskiy Nikita on 28.04.2020.
//

#ifndef LAB7_STONE_H
#define LAB7_STONE_H


#include "cell.h"


class Stone : public Object
{

public:

    Stone(Cell* cell);
    ~Stone() = default;

    bool live() override;
    char getSymbol() override;

};


#endif //LAB7_STONE_H
