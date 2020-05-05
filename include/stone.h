#ifndef LAB7_STONE_H
#define LAB7_STONE_H

#include "object.h"
class Cell;
class Stone: public Object{
public:
    explicit Stone(Cell* c);

    bool live() override ;
    char getChar() override;
};
#endif //LAB7_STONE_H
