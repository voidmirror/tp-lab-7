//
// Created by artem on 05.04.2020.
//

#include "Food.h"
#include "Cell.h"
#include "Ocean.h"

Food::Food(Cell *cell, Coordinates coordinates, OceanType oceanType) : Object(cell, coordinates, oceanType) {
    this->setView('*');
}

void Food::live() {}

