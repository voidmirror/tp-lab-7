#include "prey.h"
#include "cell.h"

Prey::Prey(Cell *c) : Object(c) {
    lifeTime = preyLife;
    reproduceTime = preyReproduce;
    typeOfObject = ObjType::PREY;
}

char Prey::getChar() {
    return 'f';
}

bool Prey::live() {
    if (!lifeTime--)
        return false;
    if (!reproduceTime--) {
        reproduce();
        reproduceTime = preyReproduce;
    } else
        move();
    return true;
}

void Prey::kill() {
    lifeTime = 0;
}

void Prey::move() {
    Cell *newCell = cell->emptyCell(cell->getPair());
    if (newCell) {
        cell->setObject(nullptr);
        cell = newCell;
        cell->setObject(this);
    }
}

void Prey::reproduce() {
    Cell *newCell = cell->emptyCell(cell->getPair());
    if (newCell) {
        Prey *child = new Prey(newCell);
        newCell->setObject(child);
        newCell->getOcean()->addStuff(child);

    }
}
