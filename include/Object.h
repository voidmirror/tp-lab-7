//
// Created by artem on 05.04.2020.
//

#ifndef OCEANEMULATOR_OBJECT_H
#define OCEANEMULATOR_OBJECT_H

#include "Coordinates.h"
#include "OceanType.h"

class Cell;

class Ocean;

class Object {

private:
    char view = 'W';
    Cell *cell;
    Coordinates coordinates;
    OceanType oceanType;
    bool isAlive = true;

protected:
    void setNewPosition(Ocean *ocean, Coordinates coordinates);

public:
    Object(Cell *cell, Coordinates coordinates, OceanType oceanType);

    ~Object();

    char getView();

    void setView(char view);

    Cell *getCell();

    void setCell(Cell *cell);

    Coordinates getCoordinates();

    void setCoordinates(Coordinates coordinates);

    virtual void live() = 0;

    OceanType getOceanType();

    bool getAlive() const;

    void setIsAlive(bool isAlive);
};


#endif //OCEANEMULATOR_OBJECT_H
