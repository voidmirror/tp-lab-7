#pragma once
#include "Object.h"
#include <vector>
#include <cstring>

class LivingObject;
class Cell;

class Ocean {
    std::vector<Coordinates*> emptyCells;
public:
    Ocean();
    Ocean(int width, int height);
    void createObjects();
    Coordinates* createCoordinates();
    Cell* getCell(int x, int yl);
    Cell* getCell(Coordinates* coordinates);
    void addObject(LivingObject* object);
    void deleteObject(LivingObject* object);
    bool isExist(int index, LivingObject* object);

    std::vector<LivingObject*> livingObjects;
    int height;
    int width;
    Cell** cells;
};