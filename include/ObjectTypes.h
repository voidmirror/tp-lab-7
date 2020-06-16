//
// Created by Anton Korkunov on 02/04/2020.
//

#ifndef LAB7_OBJECTTYPES_H
#define LAB7_OBJECTTYPES_H

#include "Object.h"

class Stone: public Object{
public:
    Stone();
    virtual void live() override;
    virtual std::string type() override;
    ~Stone(){};
};

class Prey: public Object{
protected:
    int intrv_of_birth, intrv_of_death;
public:
    Prey( int intrv_of_birth, int intrv_of_death);
    virtual void live() override;
    virtual std::string type() override;
    void Move();
    virtual void Reproduce();
    ~Prey(){};
};

class Predator: public Prey{
protected:
    int hunger;
public:
    Predator(int intrv_of_birth, int intrv_of_death, int hunger);
    virtual std::string type() override;
    virtual void live() override;
    void Reproduce() override;
    void Hunt();
    ~Predator(){};
};

#endif //LAB7_OBJECTTYPES_H
