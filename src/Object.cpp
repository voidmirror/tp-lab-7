//
// Created by Anton Korkunov on 02/04/2020.
//

#include "Object.h"

Object::Object() {
    cell=nullptr;
}

Object::~Object() {
    cell=nullptr;
}

void Object::setCell(Cell* tmp){
    cell = tmp;
};

Cell* Object::getCell(){
    return cell;
};