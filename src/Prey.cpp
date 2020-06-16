//
// Created by aklen on 23.04.2020.
//
#include "Prey.h"


Prey::Prey(Cell *cell) :Object(cell) {
    lifetime = LIFETIME_PREY;
    reproduce_time = REPRODUCE_T;
    type = ObjType::PREY;
    symbol = PREY_S;
}

char Prey::getSymbol() const {
    return this->symbol;
}


void Prey::reproduce(){
    Cell* new_cell = cell->search_empty();
    if(new_cell){
        auto* child = new Prey(new_cell);
        new_cell->setObject(child);
        new_cell->getOcean()->addStuff(child);
        reproduce_time = REPRODUCE_T;
    }
}


void Prey::move(){
    Cell* new_cell = cell->search_empty();
    if(new_cell){
        cell->setObject(nullptr);
        cell = new_cell;
        new_cell->setObject(this);
    }
}


bool Prey::live(){
    if(!lifetime--)
        return false;
    move();
    if(reproduce_time != 0)
        reproduce_time--;
    if(reproduce_time == 0){
        reproduce();
    }
    return true;
}

