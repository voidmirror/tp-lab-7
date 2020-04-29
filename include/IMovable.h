//
// Created by fiskirton on 08.04.2020.
//

#ifndef OCEAN_IMOVABLE_H
#define OCEAN_IMOVABLE_H

class IMovable{
public:
    virtual void moveUp() = 0;
    virtual void moveDown() = 0;
    virtual void moveLeft() = 0;
    virtual void moveRight() = 0;
    virtual void makeStep() = 0;
    virtual void move(int step, int axis) = 0;
};

#endif //OCEAN_IMOVABLE_H
