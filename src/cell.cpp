//
// Created by Оксана on 04.05.2020.
//

#include <cell.h>
#include <ocean.h>

void Cell::init(Pair p, Ocean *oc){
    coordinates = p;
    ocean = oc;
}

Object* Cell::getObject() const{
    return object;
}

void Cell::setObject(Object* obj){
    object = obj;
}

Pair Cell::getCoordinates() const {
    return coordinates;
}

Ocean* Cell::getOcean() const{
    return ocean;
}


Cell* Cell::findEmptyCellNear() const{
    return ocean->getEmptyCellByName(coordinates);
}

Cell* Cell::findPreyNear() const{
    return ocean->getCellByName(coordinates, ObjType::PREY);
}
Cell* Cell::findPredatorNear() const{
    return ocean->getCellByName(coordinates, ObjType::PREDATOR);
}

Cell::~Cell() {

}

Cell::Cell(Pair p, Ocean *oc) {
    coordinates = p;
    ocean = oc;
}


/*explicit Cell(Pair p = { 0, 0 }, Ocean* oc = nullptr);
~Cell();
void init(Pair coordinates, Ocean* ocean);
Object* getObject() const;
Pair getCoordinates() const;
void setObject(Object* object);
void deleteObj();
Cell* getNeighbour(bool isPredator=false);
Ocean* getOcean();
//getInformCell();*/