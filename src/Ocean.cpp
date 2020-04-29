//
// Created by fiskirton on 08.04.2020.
//

#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <random>
#include <Inanimate.h>

#include "Ocean.h"
#include "helper.h"


using namespace std;

void Ocean::makeGrid() {
    cells = new Cell * [HEIGHT];
    for (int i = 0; i < HEIGHT; ++i) {
        cells[i] = new Cell[WIDTH];
        for (int j = 0; j < WIDTH; ++j) {
            cells[i][j] = Cell(Pair{ j, i }, this);
        }
    }
}

void Ocean::fillMap() {
    int x, y;
    for (int i = 0; i < OBJECTS_NUM; ++i) {
        int objId = getRandom(1, creators.size());
        Object * object = creators[objId]->createObject();
        objects.push_back(object);
        x = getRandom(0, WIDTH - 1);
        y = getRandom(0, HEIGHT - 1);
        cells[y][x].setObject(object);
        object->setCell(&cells[y][x]);
        population[objId] += 1;
    }
}

void Ocean::printMap() {
    SetCursorPos(0, 0);
    for (int i=0; i < HEIGHT; ++i) {
        for (int j=0; j < WIDTH; ++j) {
            if (cells[i][j].getObject()) {
                cout << cells[i][j].getObject()->getObjType();
            } else {
                cout << '.';
            }
        }
        cout << endl;
    }

    cout << "fish: " << population[1] << endl;
    cout << "pfish: " << population[2] << endl;

    this_thread::sleep_for(std::chrono::milliseconds(500));
}

void Ocean::init() {

    addCreator(FISH, new FishCreator);
    addCreator(PFISH, new PredatorFishCreator);
    addCreator(STONE, new StoneCreator);

    makeGrid();
    fillMap();
    printMap();

    auto rng = std::default_random_engine {};
    int iteration = 0;
    while (population[FISH] > 0 && population[PFISH] > 0 && iteration < MAX_ITER){
        std::shuffle(std::begin(objects), std::end(objects), rng);
        for (auto obj: objects) {
            if (obj->getCell()){
                obj->init();
            }

        }

        flushNew();
        flushOld();
        printMap();

        iteration++;
    }
}

void Ocean::addCreator(int type, ObjectCreator *creator) {
    creators.insert(make_pair(type, creator));
}

Cell **Ocean::getCells() const {
    return cells;
}

void Ocean::removeObj(Object *object) {
    objects.erase(std::remove(objects.begin(), objects.end(), object), objects.end());
}

void Ocean::flushOld() {
    for (auto obj : deadObj){
        removeObj(obj);
        if (obj->getCell()){
            delete obj;
        }

    }
    deadObj.clear();
}

void Ocean::flushNew() {
    if (!newObj.empty()){
        objects.reserve(objects.size() + newObj.size());
        objects.insert(objects.end(), newObj.begin(), newObj.end());
        newObj.clear();
    }

}

void Ocean::addDead(Object *object) {
    deadObj.push_back(object);
}

void Ocean::addNew(Object *object) {
    newObj.push_back(object);
}

ObjectCreator *Ocean::getCreator(int type_id) {
    return creators[type_id];
}

map<int, int> &Ocean::getPopulation() {
    return population;
}

