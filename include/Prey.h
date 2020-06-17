#pragma once

#include "Object.h"

class Prey : public Object
{
protected:
    size_t age;
    size_t last_spawned;
    virtual void spawn();
    virtual void move();
public:
    Prey(Cell* cell) : Object{cell}, age{0}, last_spawned{0} { type = ObjType::PREY; } ;
    ~Prey() = default;

    bool live() override;
};