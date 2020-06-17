#ifndef Prey_hpp
#define Prey_hpp

#include "Cell.hpp"
#include "Object.hpp"
#include "Defaults.h"
#include <stdio.h>


class Cell;
class Ocean;

class Prey : public Object {
public:
    Prey(Cell* cell);

    char getChar() override;
    bool live() override;
    void move() override;
    void reproduce() override;

};


#endif /* Prey_hpp */
