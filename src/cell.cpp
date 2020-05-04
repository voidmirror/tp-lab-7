//
// Created by Илья Соловьёв on 05.05.2020.
//

#include "cell.h"
Cell::Cell()
{
    ocean = nullptr;
    coordinates = std::pair<size_t , size_t >(0, 0);
    object = nullptr;
}
void Cell::init(size_t coord_x, size_t coord_y, Ocean* oc)
{
    coordinates.first = coord_x;
    coordinates.second = coord_y;
    ocean = oc;
}
Object* Cell::getObject()
{
    return object;
}
void Cell::setObject(Object* newObject)
{
    object = newObject;

}
std::pair<size_t, size_t> Cell::getCoordinates()
{
    return coordinates;
}

Ocean* Cell::getOcean() {
    return ocean;
}

Cell* Cell::isPreyAround(std::pair<size_t, size_t>coords)
{
    return ocean->isPreyAround(coords);
}

Cell* Cell::isFreeCellAround(std::pair<size_t, size_t> coords)
{
    return ocean->isFreeCellAround(coords);
}