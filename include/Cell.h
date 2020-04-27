//
// Created by fiskirton on 08.04.2020.
//

#ifndef OCEAN_CELL_H
#define OCEAN_CELL_H

#include "Object.h"
#include "config.h"

class Ocean;

class Cell {

    friend Ocean;

private:
    Pair coords;
    Ocean *ocean;
    Object *object;


public:
    explicit Cell(Pair coords = { 0, 0 }, Ocean * ocean = nullptr);

public:
    Object *getObject() const;
    Ocean *getOcean() const;

    void setObject(Object *object);
    void reset();

    Cell * checkAround(bool notEmpty = false);

    const Pair &getCoords() const;
};


#endif //OCEAN_CELL_H
