//
// Created by araxal on 04.04.2020.
//

#ifndef UNTITLED_OBJECTS_H
#define UNTITLED_OBJECTS_H

#include <string>
#include "params.h"

enum {LEFT, UP, RIGHT, DOWN};

class Cell;

class Object {
private:
    Cell * myCell = nullptr;
public:
    char type;
    Cell *getMyCell();
    void setMyCell(Cell *myCell);

    Object();
    ~Object()= default;

    void destroy();
    char getType();
    virtual void live(){};
};


class Stone : public Object {
public:
    Stone();
    void live() final{/*I am Groot*/};
};


class Prey : public Object {
private:
    virtual void move();
protected:
    virtual void tryToLayEgg(Cell *);
public:
    unsigned int age = 0;
    Prey();
    unsigned int increaseAge();
    void live() override;
};


class Predator : public Prey {
    void move() override;
    void eat ();
protected:
    void tryToLayEgg(Cell *) override;
public:
    unsigned int hunger = 0;
    Predator();
    unsigned int increaseHunger();
    void live() override;
};

#endif //UNTITLED_OBJECTS_H
