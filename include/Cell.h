#pragma once
#include "Object.h"


class Cell {

    Object* object;
    Coordinates location;
    static const char character = ' ';

public:
    Cell();
    explicit Cell(Coordinates location);
    bool isEmpty();
    void printView();
    Coordinates* getLocation();
    void setLocation(Coordinates location);
    Object* getObject();
    void setObject(Object* object);
};
