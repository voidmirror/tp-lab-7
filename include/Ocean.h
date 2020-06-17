//
// Created by artem on 05.04.2020.
//

#ifndef OCEANEMULATOR_OCEAN_H
#define OCEANEMULATOR_OCEAN_H


#include <vector>
#include "Coordinates.h"
#include "OceanType.h"

class Cell;

class Object;

class Ocean {
private:
    int width;
    int height;

    Cell **cellMap;
    std::vector<Object *> objects;

    int items[4];

    void init();

    Coordinates getRandomEmpty();

    void spawnCreatures();

public:
    Ocean(int width, int height, int nStones, int nPrey, int nPredator, int nFood);

    int getWidth() const;

    void setWidth(int width);

    int getHeight() const;

    void setHeight(int height);

    Cell **getCellMap() const;

    void setCellMap(Cell **cellMap);

    void timeTick();

    void showMap();

    void spawnNewCreature(OceanType oceanType, Coordinates coordinates);

    bool checkIfExistPredators();

    bool checkIfExistSomeone();

};


#endif //OCEANEMULATOR_OCEAN_H
