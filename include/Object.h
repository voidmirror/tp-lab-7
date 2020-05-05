#ifndef OBJECT_H
#define OBJECT_H

#include "common.h"

class Ocean;
class Cell;
class Object
{
protected:
    Object(Cell* c = NULL);
    Cell *cell;
    size_t lifetime;
    Type  type;
    size_t reproduce_time;
    std::string symbol = "?";
public:
    virtual ~Object() = default;
    virtual bool live() = 0;
    virtual void move() {};
    virtual void reproduce() {};
    std::string getSymbol();
    Cell* getCell();
    Type getType();
    void setLifetime(size_t lt);
};
#endif //OBJECT_H
