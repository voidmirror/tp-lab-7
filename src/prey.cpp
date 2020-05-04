//
// Created by Илья Соловьёв on 05.05.2020.
//

#include "prey.h"
#include "cell.h"
Prey::Prey(Cell *c) : Object(c){
    lifeTime = prey_lifetime;
    reproductiveTime = prey_reproducetime;
    typeOfObject = ObjType ::PREY;
}
char Prey::getSymbol(){
    return 'f';
}
bool Prey::live() {
    if (!lifeTime--)
        return false;
    if (!reproductiveTime--)
    {
        reproduce();
        reproductiveTime = prey_reproducetime;
    }
    else
        move();
    return true;
}
void Prey::kill()
{
    lifeTime = 0;
}
void Prey::move(){
    Cell* newCell = cell->isFreeCellAround(cell->getCoordinates());
    if (newCell)
    {
        cell->setObject(nullptr);
        cell = newCell;
        cell->setObject(this);
    }
}

void Prey::reproduce() {
    Cell* newCell = cell->isFreeCellAround(cell->getCoordinates());
    if (newCell)
    {
        Prey* child = new Prey(newCell);
        newCell->setObject(child);
        newCell->getOcean()->addCreature(child);
    }
}