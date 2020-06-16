//
// Created by Ignatovskiy Nikita on 28.04.2020.
//


#include "cell.h"


void Cell::initialize(Pair pair_, Ocean *ocean_)
{
    this->ocean = ocean_;
    this->crd = pair_;
}


Cell* Cell::getNearFreeCell()
{
    return this->ocean->findEmptyField(crd);
}


Cell* Cell::getPreyAround()
{
    return this->ocean->findNearPrey(crd);
}


void Cell::setObject(Object* object_)
{
    this->object = object_;
}


Object* Cell::getObject()
{
    return this->object;
}


Ocean* Cell::getOcean()
{
    return this->ocean;
}


void Cell::kill()
{
    if (this->object)
    {
        delete this->object;
        this->object = nullptr;
    }
}
