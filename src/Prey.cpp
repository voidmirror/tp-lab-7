//
// Created by artem on 05.04.2020.
//

#include <iostream>
#include "Prey.h"
#include "Cell.h"
#include "Ocean.h"

void Prey::live() {
    Cell *cell = getCell();
    Ocean *ocean = cell->getOcean();

    int width = ocean->getWidth();
    int height = ocean->getHeight();


    int oldX = this->getCoordinates().x, oldY = this->getCoordinates().y;

    Coordinates directions[4] = {Coordinates{oldX - 1, oldY}, Coordinates{oldX, oldY - 1},
                                 Coordinates{oldX + 1, oldY}, Coordinates{oldX, oldY + 1}};
    int counter = 0;

    bool needToMove = true;

    for (auto &direction : directions) {
        int directionX = direction.x, directionY = direction.y;

        if (directionX >= 0 && directionX < width && directionY >= 0 && directionY < height
            && ocean->getCellMap()[directionY][directionX].getObject() != nullptr) {

            if (ocean->getCellMap()[directionY][directionX].getObject()->getOceanType() == foodType) {
                setNewPosition(ocean, direction);
                readyToGiveBirth = true;
                needToMove = false;
                break;
            }
        }
    }

    if (needToMove) {

        int directionIndex = rand() % 4;

        while (counter != 3) {

            int actualX = directions[directionIndex].x, actualY = directions[directionIndex].y;

            if (actualX >= 0 && actualX < width && actualY >= 0 && actualY < height) {

                if (ocean->getCellMap()[actualY][actualX].getObject() == nullptr) {
                    setNewPosition(ocean, directions[directionIndex]);
                    break;
                }

            } else {
                directionIndex = (directionIndex + 1) % 4;
            }
            counter++;
        }
    }

    if (readyToGiveBirth) {
        for (auto &direction : directions) {
            int directionX = direction.x, directionY = direction.y;

            if (directionX >= 0 && directionX < width && directionY >= 0 && directionY < height
                && ocean->getCellMap()[directionY][directionX].getObject() == nullptr) {

                ocean->spawnNewCreature(preyType, Coordinates{directionX, directionY});
                readyToGiveBirth = false;
                return;
            }
        }
    }
}

Prey::Prey(Cell *cell, Coordinates coordinates, OceanType oceanType) : Object(cell, coordinates, oceanType) {
    this->setView('v');
}


