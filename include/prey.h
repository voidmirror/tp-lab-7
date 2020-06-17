#ifndef LAB7_PREY_H
#define LAB7_PREY_H

#include "object.h"

class Cell;
class Prey: public Object{
protected:
    int lifeTime;
    int reproduceTime;
public:
    explicit Prey(Cell* c);
    bool live() override;
    char getChar() override;
    void kill();
    virtual void reproduce();
    virtual void move();

};
#endif //LAB7_PREY_H
