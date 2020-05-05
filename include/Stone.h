#ifndef STONE_H
#define STONE_H

#include "Object.h"
#include "Cell.h"
#include "Ocean.h"
#include "common.h"

class Stone : public Object
{
public:
    Stone(Cell* cell);
    ~Stone() = default;
    bool live() override;
};


#endif //STONE_H
