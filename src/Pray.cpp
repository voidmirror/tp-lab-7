//
// Created by sdanilov on 4/17/2020.
//

#include "Pray.h"
#include "ocean.h"

void Prey::move(Ocean& ocean){
    int iter_count = 0;
    while (true) {
        Cell* target = ocean.getRandomCellfromOcean();
        if (target->type == "water"){
            target->object = self->object;
            target->type = "prey";
			self->object = nullptr;
			self->type = "water";
			self = target;
            break;
        }
        else {
            iter_count++;
            if (iter_count > 10){
                break;
            }
        }
    }
}

void Prey::multiply(Ocean& ocean){
    int iter_count = 0;
    if (self == nullptr){
        return;
    }
    while (true) {
        Cell* target = ocean.getRandomCellfromOcean();
        if (target->type == "water"){
            target->object = ObjectManufacture::newObject("prey",target);
            target->type = "prey";
            break;
        }
        else {
            iter_count++;
            if (iter_count > 10){
                break;
            }
        }
    }
}