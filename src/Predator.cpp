#include "Predator.h"

void Predator::move(Ocean& ocean){
    int step_count = 0;
    while (true) {
        Cell* target = ocean.chooseCell();
        if (target->type == "water"){
            target->object = self->object;
            target->type = "predator";
			self->object = nullptr;
			self->type = "water";
			self = target;
            break;
        }
        else if (target->type == "prey") {
            target->die();
            target->object = self->object;
            target->type = "predator";
			self->object = nullptr;
			self->type = "water";
			self = target;
            break;
        }
        else{
            step_count++;
            if (step_count > 10){
                break;
            }
        }
    }
}

void Predator::propagate(Ocean& ocean){
    int step_count = 0;
    if (self == nullptr){
        return;
    }
    while (true) {
		Cell* target = ocean.chooseCell();
        if (target->type == "water"){
            target->object = Factory::newObject("predator", target);
            target->type = "predator";
            break;
        }
        else {
            step_count++;
            if (step_count > 10){
                break;
            }
        }
    }
}