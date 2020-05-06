//
// Created by artem on 06.05.2020.
//

#include "iostream"
#include "Predator.h"
#include "Prey.h"
#include "Cell.h"
#include "Ocean.h"

Predator::Predator(Cell *cell, Coordinates coordinates, OceanType oceanType) : Object(cell, coordinates, oceanType) {
    this->setView('&');
}

void Predator::live() {
    Ocean *ocean = getCell()->getOcean();

    int width = ocean->getWidth();
    int height = ocean->getHeight();

    Coordinates directions[4] = {Coordinates{this->getCoordinates().x - 1, this->getCoordinates().y},
                                 Coordinates{this->getCoordinates().x, this->getCoordinates().y - 1},
                                 Coordinates{this->getCoordinates().x + 1, this->getCoordinates().y},
                                 Coordinates{this->getCoordinates().x, this->getCoordinates().y + 1}};
    int counter = 0;

    bool needToMove = true;

    for (auto &direction : directions) {
        int directionX = direction.x, directionY = direction.y;

        if (directionX >= 0 && directionX < width && directionY >= 0 && directionY < height
            && ocean->getCellMap()[directionY][directionX].getObject() != nullptr) {

            if (ocean->getCellMap()[directionY][directionX].getObject()->getOceanType() == preyType) {
                setNewPosition(ocean, direction);
                readyToGiveBirth = true;
                timeToDie = 10;
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

                ocean->spawnNewCreature(predatorType, Coordinates{directionX, directionY});
                readyToGiveBirth = false;
                return;
            }
        }
    }

    this->timeToDie--;
    if (timeToDie < 1) {
        this->setIsAlive(false);
        getCell()->setObject(nullptr);
    }
}

