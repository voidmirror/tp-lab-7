#include "predator.h"
#include "cell.h"

Predator::Predator(Cell *c) : Prey(c) {
    lifeTime = predatorLife;
    hungryTime = predatorHunger;
    reproduceTime = predatorReproduce;
    typeOfObject = ObjType::PREDATOR;
}

char Predator::getChar() {
    return 'S';
}

bool Predator::live() {
    if ((!lifeTime--) || (!hungryTime))
        return false;
    if (!reproduceTime--) {
        reproduce();
        reproduceTime = predatorReproduce;
    } else {
        Cell *newCell = cell->preyCell(cell->getPair());
        if (newCell)
            eat(dynamic_cast<Prey *>(newCell->getObject()));
        else
            move();
    }
    return true;
}

void Predator::reproduce() {
    Cell *newCell = cell->emptyCell(cell->getPair());
    if (newCell) {
        auto child = new Predator(newCell);
        newCell->setObject(child);
        newCell->getOcean()->addStuff(child);
    }
}

void Predator::move() {
    Cell *newCell = cell->emptyCell(cell->getPair());
    if (newCell) {
        cell->setObject(nullptr);
        cell = newCell;
        cell->setObject(this);
    }
}

void Predator::eat(Prey *prey) {
    Cell *newCell = prey->getCell();
    prey->kill();
    hungryTime = 5;
    cell->setObject(nullptr);
    cell = newCell;
    cell->setObject(this);

}