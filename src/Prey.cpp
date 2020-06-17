#include "Prey.hpp"

#include "Object.hpp"
#include "Cell.hpp"
#include "Ocean.hpp"
#include "Defaults.h"



Prey::Prey(Cell *cell): Object(cell) {
    this->type = ObjType::PREY;
    this->lifetime = PREY_LIFE;
    this->reprtime = PREY_REPR;
}


char Prey::getChar() {
    return PREY_CHAR;
}

bool Prey::live() {
    if (!this->lifetime--)
        return false;
    move();
    if (this->reprtime == 0) {
        reproduce();
        this->reprtime = PREY_REPR;
    }
    this->reprtime -= 1;
    return true;
}


void Prey::move() {
    Cell* freeCell = this->cell->findCell();
    if (freeCell) {
        this->cell->setObject(nullptr);
        this->cell = freeCell;
        freeCell->setObject(this);
    }
}

void Prey::reproduce()
{
    Cell* freeCell = this->cell->findCell();
    if (freeCell) {
        auto* childPrey = new Prey(freeCell);
        freeCell->setObject(childPrey);
        freeCell->getOcean()->produceObj(childPrey);
    }
}


