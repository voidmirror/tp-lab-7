#ifndef Cell_hpp
#define Cell_hpp

#include <stdio.h>
#include "Object.hpp"
#include "Defaults.h"
#include "Ocean.hpp"
#include <random>


class Object;
class Ocean;

class Cell {
    friend Ocean;
private:
    Coord coord;
    Object *object;
    Ocean *ocean;
public:
    explicit Cell(Coord p = { 0, 0 }, Ocean* oc = nullptr) :
        coord(p),
        object(nullptr),
        ocean(oc) {}
    
    void init(Coord coord, Ocean *ocean);
    Cell* findCell();
    Cell* findPrey();
    Object* getObject();
    void setObject(Object* obj);
    void killObject();
    Coord getCoord();
    Ocean* getOcean();
};

#endif /* Cell_hpp */
