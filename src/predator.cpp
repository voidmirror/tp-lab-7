//
// Created by Оксана on 19.04.2020.
//

#include "predator.h"
#include <cell.h>
#include <ocean.h>

bool Predator::hunt() {
    Cell* preyCell = cell->findPreyNear();
    if (preyCell){
        preyCell->getObject()->die();
        setCell(preyCell);
        hungerTimer = predatorHungerlevel;
        return true;
    }
    return false;
}



void Predator::reproduce() {
    Cell* cell_to_spawn = cell->findEmptyCellNear();
    Cell* cell_partner = cell->findPredatorNear();
    if (cell_to_spawn != nullptr && cell_partner != nullptr)    {
        Prey* child_prey = new Prey(cell_to_spawn);
        cell_to_spawn->setObject(child_prey);
        cell->getOcean()->addObject(child_prey);
        reproductionTimer = predatorReproducetime;
    }
}

void Predator::move() {
    Cell* cell_to_move = cell->findEmptyCellNear();
    if (cell_to_move != nullptr)    {
        cell->setObject(nullptr);
        cell_to_move->setObject(this);
        cell = cell_to_move;
    }
}

Predator::Predator(Cell * cell): Prey(cell){
    type = ObjType::PREDATOR;
    hungerTimer = predatorHungerlevel;
    reproductionTimer = predatorReproducetime;
    lifeTimer = predatorLifetime;
    symb = 'S';
}



void Predator::live() {
    hungerTimer--;
    lifeTimer--;
    reproductionTimer--;
    if(hungerTimer){
        move();
    }
    if (reproductionTimer == 0 && hungerTimer) {
        reproduce();
    }
    if (hungerTimer == 0 || lifeTimer == 0) {
        die();
    }
}


