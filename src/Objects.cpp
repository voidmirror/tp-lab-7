//
// Created by araxal on 04.04.2020.
//

#include "../include/Objects.h"
#include "../include/Ocean.h"
#include <iostream>

void Object::destroy() {
    getMyCell()->setObject(nullptr);
    delete this;
}

Cell *Object::getMyCell(){
    return myCell;
}

void Object::setMyCell(Cell *_myCell) {
    myCell = _myCell;
}

Object::Object() {
    type = EMPTY_N;
}

char Object::getType(){
    return type;
}

void Prey::live() {
    getMyCell()->getOcean()->madeMove[this->getMyCell()->getCoords().y][this->getMyCell()->getCoords().x] = true;
    move();
    auto newAge = increaseAge();
    if (newAge >= fishLifespan){
        destroy();
    }
}

void Prey::move() {
    Cell* cellToMove = getMyCell()->getOcean()->findNewCellAround(getMyCell()->getCoords(), this);
    if (cellToMove != nullptr){//если могу переместиться
        getMyCell()->getOcean()->madeMove[cellToMove->getCoords().y][cellToMove->getCoords().x] = true;
        getMyCell()->setObject(nullptr);

        tryToLayEgg(getMyCell());

        if (cellToMove->getObject() != nullptr){
            cellToMove->getObject()->destroy();
        }

        cellToMove->setObject(this);
        setMyCell(cellToMove);
    }
}

unsigned int Prey::increaseAge() {
    return ++age;
}

Prey::Prey() {
    type = PREY_N;
}

void Prey::tryToLayEgg(Cell *c) {
    if ((random() % 100 < preyLayEggProbabilityAfterMove)&&(c->getObject() == nullptr)){
        getMyCell()->getOcean()->madeMove[c->getCoords().y][c->getCoords().x] = true;
        auto obj = new Prey();
        obj->setMyCell(c);
        c->setObject(obj);
    }
}

void Predator::live() {
    move();
    auto newAge = increaseAge();
    if (newAge >= fishLifespan || hunger >= predatorMaxHunger){
        destroy();
    }
}


void Predator::move(){
    Cell* cellToMove = getMyCell()->getOcean()->findNewCellAround(getMyCell()->getCoords(), this);
    if (cellToMove != nullptr){
        getMyCell()->setObject(nullptr);
        getMyCell()->getOcean()->madeMove[cellToMove->getCoords().y][cellToMove->getCoords().x] = true;


        if (cellToMove->getObject() != nullptr){
            cellToMove->getObject()->destroy();
            eat();
        }else{
            increaseHunger();
        }
        tryToLayEgg(getMyCell());
        cellToMove->setObject(this);
        setMyCell(cellToMove);
    }
}

void Predator::eat() {
    if (hunger > predatorHungerSatCoefficient){
        hunger = hunger - predatorHungerSatCoefficient;
    }else{
        hunger = 0;
    }
}

unsigned int Predator::increaseHunger() {
    return ++hunger;
}

Predator::Predator() {
    type = PREDATOR_N;
}

void Predator::tryToLayEgg(Cell * c) {
    if ((random() % 100 < predatorLayEggProbabilityAfterMove)&&(c->getObject() == nullptr) && (hunger==0)){
        getMyCell()->getOcean()->madeMove[c->getCoords().y][c->getCoords().x] = true;
        auto obj = new Predator();
        obj->setMyCell(c);
        c->setObject(obj);
    }
}

Stone::Stone() {
    type = STONE_N;
}
