//
// Created by Ignatovskiy Nikita on 28.04.2020.
//


#include "predator.h"


Predator::Predator(Cell *cell): Object(cell)
{
    this->type = ObjType::PREDATOR;
    this->lifetime = LIFETIME_PREDATOR;
    this->reproduceTime = REPRODUCE_TIME_PREDATOR;
}


char Predator::getSymbol()
{
    return PREDATOR_N;
}


void Predator::move()
{
    Cell* freeCell = this->cell->getNearFreeCell();

    if (freeCell)
    {
        this->cell->setObject(nullptr);
        this->cell = freeCell;
        freeCell->setObject(this);
    }
}


void Predator::reproduce()
{
    Cell* freeCell = this->cell->getNearFreeCell();

    if (freeCell)
    {
        auto* childPredator = new Predator(freeCell);
        freeCell->setObject(childPredator);
        freeCell->getOcean()->spawnObject(childPredator);
    }
}


bool Predator::eat()
{
    Cell* aimForEating = this->cell->getPreyAround();

    if (aimForEating)
    {
        aimForEating -> getObject()->setLifeTime(0);
        return true;
    }

    return false;
}


bool Predator::live()
{
    if(!this->lifetime--)
        return false;

    this->hungerLevel = eat();
    this->reproduceTime -= 1;

    if (this->hungerLevel && this->reproduceTime == 0)
    {
        reproduce();
        this->reproduceTime = REPRODUCE_TIME_PREDATOR;
    }

    if (this->reproduceTime == 0)
        this->reproduceTime = REPRODUCE_TIME_PREDATOR;

    return true;
}


