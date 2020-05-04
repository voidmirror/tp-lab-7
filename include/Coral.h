//
// Created by iddoroshenko on 29.04.2020.
//

#ifndef LAB7_CORAL_H
#define LAB7_CORAL_H

#include "Object.h"

class Coral : public Object {
public:
    Coral() : Object(ObjType::CORAL) {}
    void live() override {}
};
#endif //LAB7_CORAL_H
