//
// Created by Mikhail on 01.05.2020.
//

#ifndef TASK1_PREY_H
#define TASK1_PREY_H

#include <iostream>
#include <object.h>

class Prey : public Object {
private:
    ObjType type = ObjType::PREY;

protected:
    int lifeTime, reproduceTime;

public:
    explicit Prey(Cell*);

    bool live() override;
    virtual void die();
    virtual void reproduce();
    ObjType getType() override;
};
#endif //TASK1_PREY_H
