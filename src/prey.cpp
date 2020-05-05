//
// Created by Оксана on 19.04.2020.
//
#include <prey.h>
#include <cell.h>
#include <ocean.h>


//const int preyLifetime = 10;
//const int preyReproducetime = 5;

Prey::Prey(Cell* c) : Object(c){
    type = ObjType::PREY;
    symb = PREY_N;
    lifeTimer = preyLifetime;
    reproductionTimer = preyReproducetime;

}

void Prey::move(){
    Cell* cell_to_move = cell->findEmptyCellNear();
    if (cell_to_move != nullptr)    {
        cell->setObject(nullptr);
        cell_to_move->setObject(this);
        cell = cell_to_move;
    }
}

void Prey::reproduce(){
    Cell* cell_to_spawn = cell->findEmptyCellNear();
    Cell* cell_partner = cell->findPreyNear();
    if (cell_to_spawn != nullptr && cell_partner != nullptr)    {
        Prey* child_prey = new Prey(cell_to_spawn);
        cell_to_spawn->setObject(child_prey);
        cell->getOcean()->addObject(child_prey);
        reproductionTimer = preyReproducetime;
    }
}

void Prey::live() {
    lifeTimer--;
    reproductionTimer--;
    if (lifeTimer < 0)
        die();
    else {
        if (reproductionTimer == 0)
            this->reproduce();
        this->move();
    }
}
void Prey::die() {
    cell->getOcean()->deleteObject(getCell());
    cell = nullptr;
}
