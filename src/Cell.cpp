#include "Cell.hpp"
#include "Ocean.hpp"
#include "Defaults.h"

void Cell::init(Coord coord, Ocean *ocean) {
    this->coord = coord;
    this->ocean = ocean;
}
Cell* Cell::findCell() {
    return this->ocean->findCell(this->coord);
}
Cell* Cell::findPrey() {
    return this->ocean->findPrey(this->coord);
}
Object* Cell::getObject(){
    return this->object;
}
void Cell::setObject(Object* obj){
    this->object = obj;
}
void Cell::killObject() {
    this->object = nullptr;
}
Coord Cell::getCoord() {
    return this->coord;
}

Ocean* Cell::getOcean(){
    return this->ocean;
}
