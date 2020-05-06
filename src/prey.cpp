#include "prey.h"
#include "cell.h"
#include "object.h"

Prey::Prey(Cell* cell) : Object(cell)
{
    lifetime = LT_Prey;
    type = ObjType::PREY;
    reproduce_time = RT_Prey;
}

bool Prey::live()
{
    if (!lifetime--)
        return false;
    move();
    if (reproduce_time == 0)
    {
        reproduce();
        reproduce_time = RT_Prey;
    }
    reproduce_time--;
    return true;
}

char Prey::getChar()
{
    return PREY_N;
}

void Prey::move()
{
    Cell* new_cell = cell->findEmptyNeighbour();
    if (new_cell)
    {
        cell->setObject(nullptr);
        cell = new_cell;
        new_cell->setObject(this);
    }
}

void Prey::reproduce()
{
    Cell* new_cell = cell->findEmptyNeighbour();
    if (new_cell)
    {
        auto* child = new Prey(new_cell);
        new_cell->setObject(child);
        new_cell->getOcean()->addStuff(child);
    }
}