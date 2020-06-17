#include "Pray.h"
#include "ocean.h"

void Prey::move(Ocean& ocean){
    int step_count = 0;
    while (true) {
        Cell* target = ocean.chooseCell();
        if (target->type == "water"){
            target->object = self->object;
            target->type = "prey";
			self->object = nullptr;
			self->type = "water";
			self = target;
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

void Prey::propagate(Ocean& ocean){
    int step_count = 0;
    if (self == nullptr){
        return;
    }
    while (true) {
        Cell* target = ocean.chooseCell();
        if (target->type == "water"){
            target->object = Factory::newObject("prey",target);
            target->type = "prey";
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