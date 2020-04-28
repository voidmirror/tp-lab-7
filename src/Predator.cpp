//
// Created by aklen on 23.04.2020.
//
#include "Predator.h"


Predator::Predator(Cell *cell) :Object(cell) {
    lifetime = LIFETIME_PRED;
    reproduce_time = REPRODUCE_T;
    type = ObjType::PREDATOR;
    symbol = PREDATOR_S;
    eat_time = PREDATOR_E;
}

char Predator::getSymbol() const{
    return symbol;
}


void Predator::reproduce(){
    Cell* new_cell = cell->search_empty();
    if(new_cell){
        auto* child = new Predator(new_cell);
        new_cell->setObject(child);
        new_cell->getOcean()->addStuff(child);
        reproduce_time = REPRODUCE_T;
    }
}


void Predator::move(){
    Cell* new_cell = cell->search_empty();
    if(new_cell){
        cell->setObject(nullptr);
        cell = new_cell;
        new_cell->setObject(this);
    }
}


bool Predator::eat() {
    Cell* aim = cell->search_prey();
    if(aim != nullptr){
        aim->getObject()->set_lifetime(0);
        eat_time = PREDATOR_E;
        return true;
    }
    return false;
}

bool Predator::live(){
    if(!lifetime--)
        return false;
    bool did_it_eat = true;
    eat_time--;
    if(eat_time <= 1)
        did_it_eat = eat();
    if(!did_it_eat && eat_time == 0)
        return false;
    move();
    if(reproduce_time != 0)
        reproduce_time--;
    if(reproduce_time == 0 )
        reproduce();
    return true;
}
