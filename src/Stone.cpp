//
// Created by artem on 05.04.2020.
//

#include "Stone.h"
#include "Ocean.h"
#include "Cell.h"

void Stone::live() {

}

Stone::Stone(Cell *cell, Coordinates coordinates, OceanType oceanType) : Object(cell, coordinates, oceanType) {
    this->setView('o');
}
