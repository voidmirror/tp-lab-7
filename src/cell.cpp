#include "cell.h"

void Cell::init(Pair p, Ocean* oc)
{
    ocean = oc;
    crd = p;
}

Object* Cell::getObject() const
{
    return object;
}

Ocean* Cell::getOcean() const
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
        object = nullptr;
    }
}

Cell* Cell::findEmptyNeighbour()
{
    return ocean->findEmpty(crd);
}

Cell* Cell::findPreyNeighbour()
{
    return ocean->findPrey(crd);
}