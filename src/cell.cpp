//
// Created by Илья on 001 01.05.20.
//

#include <ocean.h>
#include "cell.h"


Object* Cell::getObject() const{
    return obj;
}

void Cell::setObject(Object* obj){
    this->obj = obj;
}

Pair Cell::getCrd(){
    return crd;
};

vector<Cell*>* Cell::getEmptyCells(){
    return ocean->getEmptyCells(this);
}

void Cell::addToOcean(Object * obj) {
    ocean->addObject(obj);
}

vector<Cell*>* Cell::getPreyCells() {
    return ocean->getCellsWithPrey(this);
}

void Cell::killMe() {
    ocean->killObject(this);
}