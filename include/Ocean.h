//
// Created by Ivan Razzhivin  on 15.05.2020.
//

#ifndef UNTITLED_OCEAN_H
#define UNTITLED_OCEAN_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <map>
#include <string>
#include "Objects.h"
#include "common.h"

class Cell;

class Ocean {
private:
    Cell *** field;
    size_t n, m;
    std::vector <Pair> randomPoints;
    bool isCellBelows(size_t x, size_t y);
    std::map <char, AliveAndHierarchy> additionalInfoMap = {
            {
                    EMPTY_N, AliveAndHierarchy(0)
            },
            {
                    PREY_N, AliveAndHierarchy(1)
            },
            {
                    PREDATOR_N, AliveAndHierarchy(2)
            },
            {
                    STONE_N, AliveAndHierarchy(9999)
            }
    };
    static Object * getRandomObject();
public:
    bool ** madeMove;
    Cell* findNewCellAround (Pair p, Object* finder);
    ~Ocean();
    void startGame();
    Ocean(size_t n, size_t m);

    std::map<char, AliveAndHierarchy> *getAdditionalInfoMap();
};


class Cell {
    Pair coords {0,0};
    Object* object = nullptr;
    Ocean* ocean = nullptr;
public:
    Cell(Pair coords, Ocean * ocean, Object* object);
    void setObject (Object * object);
    void setOcean (Ocean *_ocean);
    void setCoords (Pair _coords);
    const Pair &getCoords() const;
    Object *getObject() const;
    Ocean *getOcean() const;
    friend void signal(Cell* c);
};


#endif 