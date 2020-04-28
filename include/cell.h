//
// Created by Mary on 15.04.2020.
//

#ifndef TASK1_CELL_H
#define TASK1_CELL_H

#include <iostream>
#include "object.h"
#include "ocean.h"

class Ocean;

class Cell{
    friend Ocean;
private:
    std::pair<size_t, size_t> coordinates;
    Object* object;
    Ocean* ocean;

public:
    Cell();
    void init(size_t coord_x, size_t coord_y, Ocean* oc);
    Object* getObject();
    void setObject(Object* newObject);
    Ocean* getOcean();
    Cell* isFreeCellAround(std::pair<size_t, size_t> coords);
    Cell* isPreyAround(std::pair<size_t, size_t>coords);
    std::pair<size_t, size_t> getCoordinates();
};


#endif //TASK1_CELL_H
