//
// Created by Mikhail on 01.05.2020.
//
#include <predator.h>
#include <cell.h>
#include <ocean.h>

Predator::Predator(Cell * _cell) : Prey(_cell) {
    lifeTime = PREDATORH::lifeTime;
    reproduceTime = PREDATORH::reproduceTime;
    eatTime = PREDATORH::eatTime;
}

bool Predator::live() {
    if(lifeTime <= 0)
        return false;
    lifeTime--;
    eat();
    if(!(--reproduceTime)) {
        reproduce();
    }
    return true;
}


ObjType Predator::getType() {
    return type;
}

void Predator::eat() {
    if(eatTime) {
        eatTime--;
        auto x = cell->getNeighbours();
        for (auto coords: x) {
            auto object = cell->getOcean()->getCell(coords.first, coords.second)->getObject();
            if(object && object->getType() == ObjType::PREY && !cell->getOcean()->notUsed(coords)) {
                Cell* object1 = cell->getOcean()->getCell(coords.first, coords.second);
                cell->getOcean()->deleteObj(object1);
                cell->getOcean()->swap(cell->getPosition(), coords);
                cell->getOcean()->fill(coords);
                reproduceTime = PREDATORH::reproduceTime;
                break;
            }
        }
    }
}

void Predator::reproduce() {
    if(!eatTime)
        return;
    auto x = cell->getNeighbours();
    for (auto coords: x) {
        auto object = cell->getOcean()->getCell(coords.first, coords.second)->getObject();
        if(!object && !cell->getOcean()->notUsed(coords)) {
            Predator* object1 = new Predator(cell->getOcean()->getCell(coords.first, coords.second));
            cell->getOcean()->addObject(object1);
            cell->getOcean()->getCell(coords.first, coords.second)->setObject(object1);
            cell->getOcean()->fill(coords);
            break;
        }
    }

}

