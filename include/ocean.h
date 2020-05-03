//
// Created by Ignatovskiy Nikita on 28.04.2020.
//


#ifndef LAB7_OCEAN_H
#define LAB7_OCEAN_H


#include "common.h"
#include "cell.h"
#include "predator.h"
#include "stone.h"
#include "prey.h"
#include <list>


class Ocean
{

    friend Cell;

private:

    Cell** cells;
    std::list<Object*> creations;

public:

    Ocean();
    ~Ocean();

    int* print();
    void addStartObjects(ObjType objectType, unsigned int amount);
    void run();

    void spawnObject(Object* object);
    static void killObject(Object* object);

    Cell* findEmptyField(Pair coordinates);
    Cell* findNearPrey(Pair coordinates);

};

#endif //LAB7_OCEAN_H
