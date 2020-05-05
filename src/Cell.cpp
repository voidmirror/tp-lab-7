#include "Cell.h"

void Cell::init(Coords p, Ocean *oc)
{
    ocean = oc;
    crd = p;
}

Object* Cell::getObject()
{
    return object;
}

Ocean* Cell::getOcean()
{
    return ocean;
}


void Cell::setObject(Object* obj)
{
    object = obj;
}

void Cell::killMe()
{
    if (object)
    {
        delete object;
        object = NULL;
    }
}

Cell* Cell::getFreeCellAround()
{
    return ocean->findEmptyCell(crd);
}

Cell* Cell::getPreyAround()
{
    return ocean->findPrey(crd);
}

