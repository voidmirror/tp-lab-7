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
    obj_type = FISH_N;
    type_id = FISH;
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


void Fish::moveUp() {

   // cout << "before " << cell->getCoords().x << ' ' << cell->getCoords().y << endl;

    int y_step = cell->getCoords().y - 1;
    if (y_step < HEIGHT && y_step >= 0){
        auto cellDist = &cell->getOcean()->getCells()[y_step][cell->getCoords().x];
        if(!cellDist->getObject()){
            cellDist->setObject(this);
            cell->setObject(nullptr);
            setCell(cellDist);
        }
    }

  //  cout << "after " << cell->getCoords().x << ' ' << cell->getCoords().y << endl;

}

void Fish::moveDown() {
    int y_step = cell->getCoords().y + 1;
    if (y_step < HEIGHT && y_step >= 0){
        auto cellDist = &cell->getOcean()->getCells()[y_step][cell->getCoords().x];
        if (!cellDist->getObject()){
            cellDist->setObject(this);
            cell->setObject(nullptr);
            setCell(cellDist);
        }
    }
}

void Fish::moveLeft() {
    int x_step = cell->getCoords().x - 1;
    if (x_step < WIDTH && x_step >= 0) {
        auto cellDist = &cell->getOcean()->getCells()[cell->getCoords().y][x_step];
        if (!cellDist->getObject()) {
            cellDist->setObject(this);
            cell->setObject(nullptr);
            setCell(cellDist);

        }
    }

}

void Fish::moveRight() {
    int x_step = cell->getCoords().x + 1;
    if (x_step < WIDTH && x_step >= 0) {
        auto cellDist = &cell->getOcean()->getCells()[cell->getCoords().y][x_step];
        if (!cellDist->getObject()){
            cellDist->setObject(this);
            cell->setObject(nullptr);
            setCell(cellDist);

        }
    }
}

void Fish::breed() {
    Cell *new_cell = cell->checkAround();
    if (new_cell) {
        Object *fish = cell->getOcean()->getCreator(type_id)->createObject();
        cell->getOcean()->addNew(fish);
        new_cell->setObject(fish);
        fish->setCell(new_cell);
    }
}

void Fish::kill() {
    cell->getOcean()->addDead(this);
    cell->setObject(nullptr);
    setCell(nullptr);
}

void Fish::update() {
    lifeTime -= 1;
    breedingSeason -= 1;
}

PredatorFish::PredatorFish(){
    obj_type = PFISH_N;
    type_id = PFISH;
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

void PredatorFish::kill() {
    Fish::kill();
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
