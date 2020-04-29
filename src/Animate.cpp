//
// Created by fiskirton on 08.04.2020.
//

#include "Cell.h"
#include "Animate.h"
#include "Ocean.h"
#include "helper.h"

using namespace std;

Animate::~Animate()= default;

Fish::Fish(){
    lifeTime = 10;
    breedingSeason = 3;
    obj_type = FISH_N;
    type_id = FISH;
    maxDescendants = getRandom(3, 5);

}

void Fish::init() {

    if (!lifeTime){
        kill();
        return;
    }

    if (!breedingSeason){
        breed();
    }

    makeStep();
    update();

}

void Fish::makeStep() {
    int dice = getRandom(0, 3);
    switch (dice){
        case UP:
            moveUp();
            break;
        case DOWN:
            moveDown();
            break;
        case LEFT:
            moveLeft();
            break;
        case RIGHT:
            moveRight();
            break;
        default:
            break;
    }
}

void Fish::move(int stepDir, int axis) {
    Cell *cellDist = nullptr;
    if (stepDir < axis && stepDir >= 0){
        if (axis == HEIGHT){
            cellDist = &cell->getOcean()->getCells()[stepDir][cell->getCoords().x];
        } else {
            cellDist = &cell->getOcean()->getCells()[cell->getCoords().y][stepDir];
        }
        if(!cellDist->getObject()){
            cellDist->setObject(this);
            cell->setObject(nullptr);
            setCell(cellDist);
        }
    }
}

void Fish::moveUp() {
    int y_step = cell->getCoords().y - 1;
    move(y_step, HEIGHT);
}

void Fish::moveDown() {
    int y_step = cell->getCoords().y + 1;
    move(y_step, HEIGHT);
}

void Fish::moveLeft() {
    int x_step = cell->getCoords().x - 1;
    move(x_step, WIDTH);
}

void Fish::moveRight() {
    int x_step = cell->getCoords().x + 1;
    move(x_step, WIDTH);
}

void Fish::breed() {
    Cell *new_cell;
    for (int i = 0; i < maxDescendants; ++i) {
        new_cell = cell->checkAround();
        if (new_cell) {
            Object *fish = cell->getOcean()->getCreator(type_id)->createObject();
            releaseToOcean(fish);
            new_cell->setObject(fish);
            fish->setCell(new_cell);
        }
    }
}

void Fish::update() {
    lifeTime -= 1;
    breedingSeason -= 1;
}

PredatorFish::PredatorFish(){
    lifeTime = 15;
    breedingSeason = 5;
    obj_type = PFISH_N;
    type_id = PFISH;
    maxDescendants = getRandom(1, 3);
}

void PredatorFish::init() {
    if (satietyLevel <= HUNGRY){
        kill();
        return;
    }
    Fish::init();
}

bool PredatorFish::hunt() {
    Cell * prey_cell = cell->checkAround(true);
    if (prey_cell) {
        prey_cell->getObject()->kill();
        satietyLevel = FULL;
        if (cell->getCoords().x > prey_cell->getCoords().x) {
            moveLeft();
        }
        if (cell->getCoords().x < prey_cell->getCoords().x) {
            moveRight();
        }
        if (cell->getCoords().y > prey_cell->getCoords().y) {
            moveUp();
        }
        if (cell->getCoords().y < prey_cell->getCoords().y) {
            moveDown();
        }
        return true;
    }
    return false;
}

void PredatorFish::breed() {
    if (satietyLevel > NORMAL && satietyLevel <= FULL){
        Fish::breed();
    }
}

void PredatorFish::update() {
    Fish::update();
    satietyLevel -= 1;
}

void PredatorFish::makeStep() {
    if (!hunt()){
        Fish::makeStep();
    }
}

void Animate::releaseToOcean(Object * object) {
    cell->getOcean()->addNew(object);
    cell->getOcean()->getPopulation()[object->getTypeId()] += 1;
}

void Animate::kill() {
    cell->getOcean()->getPopulation()[this->getTypeId()] -= 1;
    cell->getOcean()->addDead(this);
    cell->setObject(nullptr);
    setCell(nullptr);

}
