#include "Predator.h"
#include "Cell.h"
#include "Object.h"
#include "common.h"

Predator::Predator(Cell *cell): Fish(cell)
{
    lifetime = PREDATORLIFETIME;
    type = Type::PREDATOR;
    reproduce_time = REPRODUCETIME;
    this->symbol = "🦈";
};
bool Predator::live()
{
    if(!lifetime--)
        return false;
    fed = eatTo();
    reproduce();
    move();
    return true;
}

bool Predator::eatTo()
{
    Cell* food = cell->getPreyAround();
    if (food)
    {
        food -> getObject()->setLifetime(0);
        return true;
    }
    return false;
}

void Predator::reproduce()
{
    if (fed && reproduce_time <= 0)
    {
        Cell* newCell = cell->getFreeCellAround();
        if (newCell)
        {
            auto* child = new Predator(newCell);
            newCell->setObject(child);
            newCell->getOcean()->addStuff(child);
            reproduce_time = REPRODUCETIME;
        }
    }
    reproduce_time--;
}
