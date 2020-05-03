//
// Created by Ignatovskiy Nikita on 28.04.2020.
//


#include "prey.h"


Prey::Prey(Cell *cell): Object(cell)
{
    this->type = ObjType::PREY;
    this->lifetime = LIFETIME_PREY;
    this->reproduceTime = REPRODUCE_TIME_PREY;
}


char Prey::getSymbol()
{
    return PREY_N;
}


void Prey::move()
{
    Cell* freeCell = this->cell->getNearFreeCell();

    if (freeCell)
    {
        this->cell->setObject(nullptr);
        this->cell = freeCell;
        freeCell->setObject(this);
    }
}

void Prey::reproduce()
{
    Cell* freeCell = this->cell->getNearFreeCell();

    if (freeCell)
    {
        auto* childPrey = new Prey(freeCell);
        freeCell->setObject(childPrey);
        freeCell->getOcean()->spawnObject(childPrey);
    }
}


bool Prey::live()
{
    if (!this->lifetime--)
        return false;

    move();

    if (this->reproduceTime == 0)
    {
        reproduce();
        this->reproduceTime = REPRODUCE_TIME_PREY;
    }

    this->reproduceTime -= 1;

    return true;
}