#ifndef LAB7_PREDATOR_H
#define LAB7_PREDATOR_H

#include "prey.h"
class Cell;
class Predator: public Prey{
private:
    int hungryTime;
public:
    explicit Predator(Cell* c);
    bool live() override;
    char getChar() override;
    void move() override;
    void reproduce() override;
    void eat(Prey* prey);
};
#endif //LAB7_PREDATOR_H
