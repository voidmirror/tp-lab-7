#include "Ocean.h"
#include "Stone.h"
#include "Prey.h"
#include "Cell.h"
#include "Predator.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

Ocean::Ocean() : Ocean(5,5){}

Ocean::Ocean(int width, int height){
    this->width = width;
    this->height = height;
    cells = new Cell*[height];
    for (int i = 0; i < height; i++){
        cells[i] = new Cell[width];
        for (int j = 0; j < width; j++) {
            cells[i][j].setLocation(Coordinates{j, i});
            emptyCells.push_back(cells[i][j].getLocation());
        }
    }
}

void Ocean::createObjects() {
    srand(time(nullptr));

    for (int i = 0; i < (int)(width*height*0.3); i++) {
        Coordinates* coordCell = createCoordinates();
        auto stone = new Stone(*coordCell, this);
        cells[coordCell->y][coordCell->x].setObject(stone);
    }

    for (int i = 0; i < (int)(width * height * 0.2); i++) {
        Coordinates* coordCell = createCoordinates();
        Prey* prey = new Prey(*coordCell, this);
        prey->birth();
    }

    for (int i = 0; i < (int)(width * height * 0.1); i++) {
        Coordinates* coordCell = createCoordinates();
        auto predator = new Predator(*coordCell, this);
        predator->birth();
    }
}

Coordinates* Ocean::createCoordinates() {
    srand(time(nullptr));
    int index = rand() % emptyCells.size();
    emptyCells.erase(emptyCells.begin() + index);
    return emptyCells[index];
}

Cell* Ocean::getCell(int x, int y) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        return &cells[y][x];
    }
    return nullptr;
}

Cell* Ocean::getCell(Coordinates* coordinates) {
    return getCell(coordinates->x, coordinates->y);
}

void Ocean::addObject(LivingObject* object) {
    livingObjects.push_back(object);
}

void Ocean::deleteObject(LivingObject* object) {
    for (int i = 0; i < livingObjects.size(); i++) {
        if (livingObjects[i] == object) {
            livingObjects.erase(livingObjects.begin() + i);
            break;
        }
    }
}

bool Ocean::isExist(int index, LivingObject* object) {
    if (index < livingObjects.size() - 1) {
        index = (int)livingObjects.size() - 1;
    }
    for (int i = 0; i <= index; i++) {
        if (livingObjects[i] == object) {
            return true;
        }
    }
    return false;
} 