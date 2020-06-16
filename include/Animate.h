//
// Created by fiskirton on 08.04.2020.
//

#ifndef OCEAN_ANIMATE_H
#define OCEAN_ANIMATE_H

#include "Object.h"
#include "IMovable.h"
#include "IPredatory.h"

enum Direction {UP, DOWN, LEFT, RIGHT};

class Animate: public Object {
protected:
    int lifeTime;
    int breedingSeason;
    int maxDescendants;

protected:
    virtual void breed() = 0;
    virtual void releaseToOcean(Object *object) final;
    virtual void kill() final ;

protected:
    ~Animate() override;
};

class Fish: public Animate, public IMovable{
protected:
    int step{1};

protected:
    void breed() override;
    void moveUp() override;
    void moveDown() override;
    void moveLeft() override;
    void moveRight() override;
    void move(int, int) override;
    void makeStep() override;
    void update() override;

public:
    Fish();

public:
    void init() override;
};

class PredatorFish: public Fish, public IPredatory{
protected:
    int satietyLevel{NORMAL};
protected:
    void breed() override;
    bool hunt() override;
    void update() override;
    void makeStep() override;

public:
    PredatorFish();

public:
    void init() override;
};

#endif //OCEAN_ANIMATE_H
