#include "../include/Cell.h"
#include "../include/Object.h"
#include "../include/Ocean.h"

void Cell::init(Pair p, Ocean* oc)
{
    crd = p;
    ocean = oc;
}

void Cell::setObject(Object* object)
{
    obj = object;
}

void Cell::killMe()
{
    if(obj != nullptr)
    {
        ObjType type = obj->getType();
        switch (type) {
            case ObjType::PREY:
            {
                getOcean()->preys--;
                break;
            }
            case ObjType::PREDATOR:
            {
                getOcean()->predators--;
                break;
            }
        }
        getOcean()->stuff.remove(obj);
        obj->getCell()->setObject(nullptr);
        delete obj;
        obj = nullptr;

    }
}

bool Cell::isEmpty() const
{
    return (obj == nullptr);
}

Object* Cell::getObj() const
{
    return obj;
}

Ocean* Cell::getOcean() const
{
    return ocean;
}

Cell *Cell::findEmptyCell() const
{
    return ocean->findEmptyCell(crd);
}

Cell *Cell::findType(ObjType type) const
{
    return ocean->findType(crd,type);
}


