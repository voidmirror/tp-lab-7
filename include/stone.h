//
// Created by Mary on 15.04.2020.
//

#ifndef TASK1_STONE_H
#define TASK1_STONE_H
#include "object.h"
class Cell;
class Stone: public Object{
public:
    explicit Stone(Cell* c): Object(c){
        typeOfObject = ObjType ::STONE;
    }

    char getSymbol() override {
        return '#';
    }
    bool live() override{
        return true;
    };
};
#endif //TASK1_STONE_H
