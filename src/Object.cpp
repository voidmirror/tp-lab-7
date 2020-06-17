//
// Created by artem on 05.04.2020.
//

#include "Object.h"
#include "Cell.h"
#include "Ocean.h"


Object::~Object() {

}

char Object::getView() {
    return view;
}

Object::Object(Cell *cell, Coordinates coordinates, OceanType oceanType) {
    this->cell = cell;
    this->coordinates.x = coordinates.x;
    this->coordinates.y = coordinates.y;
    this->oceanType = oceanType;
}

void Object::setView(char view) {
    this->view = view;
}

Cell *Object::getCell() {
    return cell;
}

void Object::setCell(Cell *cell) {
    this->cell = cell;
}

Coordinates Object::getCoordinates() {
    return coordinates;
}

void Object::setCoordinates(Coordinates coordinates) {
    this->coordinates.x = coordinates.x;
    this->coordinates.y = coordinates.y;
}

OceanType Object::getOceanType() {
    return oceanType;
}


void Object::setNewPosition(Ocean *ocean, Coordinates coordinates) {
    Cell *actualCell = &ocean->getCellMap()[coordinates.y][coordinates.x];

    if (actualCell->getObject() != nullptr) {
        actualCell->getObject()->isAlive = false;
    }

    actualCell->setObject(this);

    setCoordinates(Coordinates{coordinates.x, coordinates.y});

    getCell()->setObject(nullptr);
    setCell(actualCell);
}

bool Object::getAlive() const {
    return isAlive;
}

void Object::setIsAlive(bool isAlive) {
    Object::isAlive = isAlive;
}




