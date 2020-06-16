//
// Created by Mikhail on 01.05.2020.
//
#include <prey.h>
#include <ocean.h>
#include <cell.h>

Prey::Prey(Cell *_cell) : Object(_cell) {
    lifeTime = PREYH::lifeTime;
    reproduceTime = PREYH::reproduceTime;
}

bool Prey::live() {
    if (lifeTime > 0) {
        lifeTime--;
        if (!(--reproduceTime)) {
            this->reproduce();
            reproduceTime = PREYH::reproduceTime;
        }
        auto x = cell->getNeighbours();
        for (auto coords: x) {
            auto object = cell->getOcean()->getCell(coords.first, coords.second)->getObject();
            if(!object && !cell->getOcean()->notUsed(coords)) {
                cell->getOcean()->fill(coords);
                cell->getOcean()->swap(cell->getPosition(), coords);
                break;
            }
        }
        return true;
    }
    return false;
}

void Prey::die() {
    lifeTime = 0;
}

ObjType Prey::getType() {
    return type;
}

void Prey::reproduce() {
    auto x = cell->getNeighbours();
    for (auto coords: x) {
        auto object = cell->getOcean()->getCell(coords.first, coords.second)->getObject();
        if(!object && !cell->getOcean()->notUsed(coords)) {
            Prey* object1 = new Prey(cell->getOcean()->getCell(coords.first, coords.second));
            cell->getOcean()->addObject(object1);
            cell->getOcean()->getCell(coords.first, coords.second)->setObject(object1);
            cell->getOcean()->fill(coords);
            break;
        }
    }
}


