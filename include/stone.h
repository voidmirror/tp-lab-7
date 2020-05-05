//
// Created by Mikhail on 01.05.2020.
//

#ifndef TASK1_STONE_H
#define TASK1_STONE_H

#include <iostream>
#include <object.h>

class Stone : public Object {
private:
    ObjType type = ObjType::STONE;
public:
    Stone(Cell*);
    bool live() override;
    ObjType getType() override;
};
#endif //TASK1_STONE_H
