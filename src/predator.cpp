//
// Created by Илья Соловьёв on 05.05.2020.
//

#include "predator.h"
#include "cell.h"
Predator::Predator(Cell *c) : Prey(c){
    lifeTime = predator_lifetime;
    famineTime = predator_faminetime;
    reproductiveTime = predator_reproducetime;
    typeOfObject = ObjType ::PREDATOR;
}

char Predator::getSymbol() {
    return 'S';
}

bool Predator::live() {
    if ((!lifeTime-- )||(!famineTime))
        return false;
    if (!reproductiveTime--)
    {
        reproduce();
        reproductiveTime = predator_reproducetime;
    }
    else
    {
        Cell* newCell = cell->isPreyAround(cell->getCoordinates());
        if (newCell)
            eat(dynamic_cast<Prey*>(newCell->getObject()));
        else
            move();
    }
    return true;
}

void Predator::reproduce()
{
    Cell* newCell = cell->isFreeCellAround(cell->getCoordinates());
    if (newCell)
    {
        auto child = new Predator(newCell);
        newCell->setObject(child);
        newCell->getOcean()->addCreature(child);
    }
}

void Predator::move()
{
    Cell* newCell = cell->isFreeCellAround(cell->getCoordinates());
    if (newCell)
    {
        cell->setObject(nullptr);
        cell = newCell;
        cell->setObject(this);
    }
}

void Predator::eat(Prey* prey)
{
    Cell*  newCell = prey->getCell();
    prey->kill();
    famineTime = 5;
    cell->setObject(nullptr);
    cell = newCell;
    cell->setObject(this);

}