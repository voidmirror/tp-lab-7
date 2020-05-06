#include "predator.h"
#include "cell.h"
#include "object.h"

Predator::Predator(Cell* cell) : Object(cell)
{
    lifetime = LT_Predator;
    type = ObjType::PREDATOR;
    reproduce_time = RT_Predator;
};
bool Predator::live()
{
    if (!lifetime--)
        return false;
    fed = eat();
    reproduce_time--;
    if (fed && reproduce_time == 0)
    {
        reproduce();
        reproduce_time = RT_Predator;
    }
    if (reproduce_time == 0)
        reproduce_time = RT_Predator;
    return true;
}

char Predator::getChar()
{
    return PREDATOR_N;
}

bool Predator::eat()
{
    Cell* aim = cell->findPreyNeighbour();
    if (aim)
    {
        aim->getObject()->setLifetime(0);
        return true;
    }
    return false;
}

void Predator::move()
{
    Cell* new_cell = cell->findEmptyNeighbour();
    if (new_cell)
    {
        cell->setObject(nullptr);
        cell = new_cell;
        new_cell->setObject(this);
    }
}

void Predator::reproduce()
{
    Cell* new_cell = cell->findEmptyNeighbour();
    if (new_cell)
    {
        auto* child = new Predator(new_cell);
        new_cell->setObject(child);
        new_cell->getOcean()->addStuff(child);
    }
}