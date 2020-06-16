//
// Created by iddoroshenko on 28.04.2020.
//

#ifndef LAB7_STONE_H
#define LAB7_STONE_H

#include "Object.h"

class Stone : public Object {
public:
    Stone() : Object(ObjType::STONE) {}
    void live() override {}
};



#endif //LAB7_STONE_H
