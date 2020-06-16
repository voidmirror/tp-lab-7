//
// Created by fiskirton on 08.04.2020.
//

#include "Cell.h"
#include "Ocean.h"

Cell::Cell(Pair coords, Ocean *ocean):
    coords(coords),
    ocean(ocean),
    object(nullptr){}

Object *Cell::getObject() const {
    return object;
}

Ocean *Cell::getOcean() const {
    return ocean;
}

void Cell::setObject(Object *object) {
    Cell::object = object;
}

const Pair &Cell::getCoords() const {
    return coords;
}

void Cell::reset() {
    object = nullptr;
}

Cell *Cell::checkAround(bool notEmpty) {
    Cell *currentCell;

    int leftEdge = coords.x - 1;
    int rightEdge = coords.x + 1;
    int topEdge = coords.y - 1;
    int bottomEdge = coords.y + 1;

    if (leftEdge < 0) {
        leftEdge = coords.x;
    }
    if (rightEdge >= WIDTH){
        rightEdge = coords.x;
    }
    if (topEdge < 0){
        topEdge = coords.y;
    }
    if (bottomEdge >= HEIGHT){
        bottomEdge = coords.y;
    }

    for (int i = topEdge; i <= bottomEdge; ++i) {
        for (int j = leftEdge; j <= rightEdge; ++j) {
            currentCell = &ocean->getCells()[i][j];
            if (notEmpty){
                if (currentCell->getObject() && currentCell->getObject()->getObjType() == FISH_N){
                    return currentCell;
                }
            } else {
                if (!currentCell->getObject()){
                    return currentCell;
                }
            }
        }
    }

    return nullptr;
}
