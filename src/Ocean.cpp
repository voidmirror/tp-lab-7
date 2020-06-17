//
// Created by artem on 05.04.2020.
//

#include <iostream>
#include "Ocean.h"
#include "Coordinates.h"
#include "Stone.h"
#include "Food.h"
#include "Prey.h"
#include "Cell.h"
#include "Predator.h"

Ocean::Ocean(int width, int height, int nStones, int nPrey, int nPredator, int nFood) {
    this->width = width;
    this->height = height;
    this->items[0] = nStones;
    this->items[2] = nPrey;
    this->items[3] = nPredator;
    this->items[1] = nFood;

    if (width * height >= nStones + nPredator + nPrey + nFood) {
        init();
        spawnCreatures();
        showMap();
    }
}

void Ocean::init() {
    cellMap = new Cell *[height];
    for (int i = 0; i < height; i++) {
        cellMap[i] = new Cell[width];
        for (int j = 0; j < width; j++) {
            Cell *cell = new Cell();
            cell->setOcean(this);
            cellMap[i][j] = *cell;
        }
    }
}

void Ocean::spawnCreatures() {
    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < items[j]; i++) {
            Coordinates randomCoords = getRandomEmpty();
            Cell *cell = &cellMap[randomCoords.y][randomCoords.x];
            switch (j) {
                case 0:
                    objects.push_back(new Stone(cell, randomCoords, stoneType));
                    break;
                case 1:
                    objects.push_back(new Food(cell, randomCoords, foodType));
                    break;
                case 2:
                    objects.push_back(new Prey(cell, randomCoords, preyType));
                    break;
                case 3:
                    objects.push_back(new Predator(cell, randomCoords, predatorType));
                    break;
                default:
                    break;
            }
            cell->setObject(objects[objects.size() - 1]);

        }
    }
}

Coordinates Ocean::getRandomEmpty() {
    int randomX = rand() % width, randomY = rand() % height;

    if (cellMap[randomY][randomX].getObject() == nullptr) {
        return Coordinates{randomX, randomY};
    }

    while (true) {

        if (randomX == width - 1) {
            randomX = 0;
            if (randomY == height - 1) {
                randomY = 0;
            } else {
                randomY++;
            }
        } else {
            randomX++;
        }
        if (cellMap[randomY][randomX].getObject() == nullptr) {
            return Coordinates{randomX, randomY};
        }

    }
}

void Ocean::timeTick() {
    for (int i = 0; i < objects.size(); i++) {
        if (objects[i]->getAlive()) {
            objects[i]->live();
        }
    }
    for (int i = 0; i < objects.size(); i++) {
        if (!objects[i]->getAlive()) {
            objects.erase(objects.begin() + i);
        }
    }
}

void Ocean::showMap() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            std::cout << cellMap[i][j].getView() << " ";
        }
        std::cout << "\n";
    }
}

int Ocean::getWidth() const {
    return width;
}

void Ocean::setWidth(int width) {
    Ocean::width = width;
}

int Ocean::getHeight() const {
    return height;
}

void Ocean::setHeight(int height) {
    Ocean::height = height;
}

Cell **Ocean::getCellMap() const {
    return cellMap;
}

void Ocean::setCellMap(Cell **cellMap) {
    Ocean::cellMap = cellMap;
}

void Ocean::spawnNewCreature(OceanType oceanType, Coordinates coordinates) {
    Cell *cell = &cellMap[coordinates.y][coordinates.x];
    switch (oceanType) {
        case preyType: {
            objects.push_back(new Prey(cell, coordinates, preyType));
            break;
        }
        case stoneType:
            break;
        case foodType:
            break;
        case predatorType:
            objects.push_back(new Predator(cell, coordinates, predatorType));
            break;
    }
    cell->setObject(objects[0]);
}

bool Ocean::checkIfExistPredators() {
    for (int i = 0; i < objects.size(); i++) {
        if (objects[i]->getAlive() && objects[i]->getOceanType() == predatorType) {
            return true;
        }
    }
    return false;
}

bool Ocean::checkIfExistSomeone() {
    for (int i = 0; i < objects.size(); i++) {
        if (objects[i]->getAlive() &&
            (objects[i]->getOceanType() == predatorType || objects[i]->getOceanType() == preyType)) {
            return true;
        }
    }
    return false;
}


