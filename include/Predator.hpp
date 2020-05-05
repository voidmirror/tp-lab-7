#ifndef Predator_hpp
#define Predator_hpp

#include "Predator.hpp"
#include "Cell.hpp"
#include "Object.hpp"
#include "Defaults.h"


class Predator : public Object {
private:
    bool isHungry = false;

public:
    Predator(Cell* cell);

    char getChar() override;
    bool live() override;
    void move() override;
    void reproduce() override;
    bool eat();

};
#endif /* Predator_hpp */
