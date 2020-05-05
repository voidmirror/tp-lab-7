#include "Predator.hpp"
#include "Cell.hpp"
#include "Defaults.h"

Predator::Predator(Cell *cell): Object(cell)
{
    this->type = ObjType::PREDATOR;
    this->lifetime = PRED_LIFE;
    this->reprtime = PRED_REPR;
}


char Predator::getChar() {
    return PRED_CHAR;
}


void Predator::move() {
    Cell* freeCell = this->cell->findCell();
    if (freeCell) {
        this->cell->setObject(nullptr);
        this->cell = freeCell;
        freeCell->setObject(this);
    }
}


void Predator::reproduce() {
    Cell* freeCell = this->cell->findCell();
    if (freeCell) {
        auto* childPredator = new Predator(freeCell);
        freeCell->setObject(childPredator);
        freeCell->getOcean()->produceObj(childPredator);
    }
}


bool Predator::eat() {
    Cell* breakfast = this->cell->findPrey();
    if (breakfast) {
        breakfast -> getObject()->setLifetime(0);
        return true;
    }
    return false;
}


bool Predator::live() {
    if(!this->lifetime--)
        return false;
    this->isHungry = eat();
    this->reprtime -= 1;
    if (this->isHungry && this->reprtime == 0)  {
        reproduce();
        this->reprtime = PRED_REPR;
    }
    if (this->reprtime == 0) {
        this->reprtime = PRED_REPR;
    }
    return true;
}
