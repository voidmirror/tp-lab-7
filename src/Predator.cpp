//
// Created by sdanilov on 4/17/2020.
//

#include "Predator.h"

void Predator::move(Ocean& ocean){
    int iter_count = 0;
    while (true) {
        Cell* target = ocean.getRandomCellfromOcean();
        if (target->type == "water"){
            target->object = self->object;
            target->type = "predator";
			self->object = nullptr;
			self->type = "water";
			self = target;
            break;
        }
        else if (target->type == "prey") {
            target->kill();
            target->object = self->object;
            target->type = "predator";
			self->object = nullptr;
			self->type = "water";
			self = target;
            break;
        }
        else{
            iter_count++;
            if (iter_count > 10){
                break;
            }
        }
    }
}

void Predator::multiply(Ocean& ocean){
    int iter_count = 0;
    if (self == nullptr){
        return;
    }
    while (true) {
		Cell* target = ocean.getRandomCellfromOcean();
        if (target->type == "water"){
            target->object = ObjectManufacture::newObject("predator", target);
            target->type = "predator";
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