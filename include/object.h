#pragma once
#include "common.h"

#define STONE_N '#'
#define CORAL_N '*'
#define PREY_N 'f'
#define PREDATOR_N 'S'

enum class ObjType { STONE, CORAL, PREY, PREDATOR };

class Ocean;
class Cell;
class Object
{
public:
    Object(Cell* c = nullptr);
    virtual ~Object() = default;
    virtual bool live() = 0; 
    virtual char getChar() = 0;
    virtual void move() {};
    virtual void reproduce() {};
    Cell* getCell();
    ObjType getType();
    void setLifetime(size_t lt);
protected:
    Cell* cell;
    size_t lifetime;
    ObjType  type;
    size_t reproduce_time;
};