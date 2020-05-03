//
// Created by Ignatovskiy Nikita on 28.04.2020.
//


#ifndef LAB7_OBJECT_H
#define LAB7_OBJECT_H


#include <cstdio>


enum class ObjType {STONE, PREY, PREDATOR};

class Ocean;
class Cell;
class Object
{
protected:

    Cell *cell;
    ObjType type;
    size_t lifetime{};
    size_t reproduceTime{};

public:

    explicit Object(Cell *c);
    virtual ~Object() = default;

    virtual char getSymbol() = 0;

    virtual bool live() = 0;
    virtual void move() {};
    virtual void reproduce() {};

    Cell* getCell();
    ObjType getType();

    void setLifeTime(int lifetimeValue);

};


#endif //LAB7_OBJECT_H
