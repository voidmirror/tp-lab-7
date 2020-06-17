#pragma once

#include "Prey.h"

class Predator : public Prey {
private:
    bool hunger;
    size_t days_starving;
    void spawn() override;
    void move() override;
public:
    Predator(Cell* cell) : Prey{cell}, hunger{true}, days_starving{2} { type = ObjType::PREDATOR; };
    ~Predator() = default;
    bool live() override;
};