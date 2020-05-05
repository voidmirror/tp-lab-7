#include "cell.h"

Cell::Cell() {
    coord.x = 0;
    coord.y = 0;
    ocean = nullptr;
    object = nullptr;
}

void Cell::init(int coord_x, int coord_y, Ocean *ocean1) {
    coord.x = coord_x;
    coord.y = coord_y;
    ocean = ocean1;
}

Object *Cell::getObject() {
    return object;
}

void Cell::setObject(Object *obj) {
    object = obj;
}

Pair Cell::getPair() {
    return coord;
}

Ocean *Cell::getOcean() {
    return ocean;
}

Cell *Cell::preyCell(Pair coords) {
    return ocean->preyCell(coords);
}

Cell *Cell::emptyCell(Pair coords) {
    return ocean->emptyCell(coords);
}