#include "Prey.h"
#include "Cell.h"
#include "Object.h"

Prey::Prey(Cell *cell): Fish(cell)
{
    lifetime = PREYLIFETIME;
    type = Type::PREY;
    reproduce_time = REPRODUCETIME;
    this->symbol = "🐟";
}

bool Prey::live()
{
    if (!lifetime--)
        return false;
    move();
    reproduce();
    return true;
}

void Prey::move()
{
    Cell* newCell = cell->getFreeCellAround();
    if (newCell)
    {
        cell->setObject(NULL);
        cell = newCell;
        newCell->setObject(this);
    }
}

void Prey::reproduce()
{
    if (reproduce_time<=0)
    {
        Cell* newCell = cell->getFreeCellAround();
        if (newCell)
        {
            auto* child = new Prey(newCell);
            newCell->setObject(child);
            newCell->getOcean()->addStuff(child);
            reproduce_time = REPRODUCETIME;
        }
    }
    reproduce_time--;
}
