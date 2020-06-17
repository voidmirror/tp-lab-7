#ifndef TASK1_FISH_H
#define TASK1_FISH_H
#include <random>
#include "Object.h"
#include "ocean.h"

class Fish : public Object{
    virtual void move(Ocean& ocean) = 0;
    virtual void propagate(Ocean& ocean) = 0;
    void live(Ocean& ocean) override {
        int random = rand()%100;
        if (random < 90){
            move(ocean);
        }
        else{
            propagate(ocean);
        };
    }
};


#endif
