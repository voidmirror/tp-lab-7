#include "Fish.h"

Fish::Fish(Cell *cell): Object(cell)
{
}

void Fish::move()
{
    Cell* newCell = cell->getFreeCellAround();
    if (newCell)
    {
        cell->setObject(NULL);
        cell = newCell;
        newCell->setObject(this);
    }
}

