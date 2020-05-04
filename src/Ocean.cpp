//
// Created by iddoroshenko on 26.03.2020.
//

#include <iostream>
#include "Ocean.h"
#include <vector>
#include <algorithm>
#include <random>
#include <unordered_set>
Ocean::Ocean() : countPredator(0), countPrey(0) {
    cells = new Cell* [N];
    for (int i = 0; i < N; ++i) {
        cells[i] = new Cell [M];
    }
}

Ocean::~Ocean() {
    auto iter = stuff.begin();
    while(iter != stuff.end()) {
        delete *iter;
        iter = stuff.erase(iter);
    }
    for (int i = 0; i < N; ++i) {
        delete [] cells[i];
    }
    delete [] cells;
}

void Ocean::print() const{
    std::cout << "Predators: " << getNumPredators() << " Preys: " << getNumPreys() << std::endl;
    for (coord_t i = 0; i < N; ++i) {
        for (coord_t j = 0; j < M; ++j) {
            if(cells[i][j].getObject()->getObjType() == ObjType::PREDATOR)
                std::cout << PREDATOR_N;
            if(cells[i][j].getObject()->getObjType() == ObjType::CORAL)
                std::cout << CORAL_N;
            if(cells[i][j].getObject()->getObjType() == ObjType::PREY)
                std::cout << PREY_N;
            if(cells[i][j].getObject()->getObjType() == ObjType::STONE)
                std::cout << STONE_N;
        }
        std::cout << std::endl;
    }
}

void Ocean::addObjects(std::list<Object*>& _stuff) {
    if (_stuff.size() != N*M) {
        std::cout << "Wrong size of stuff!" << std::endl;
    }

    std::vector<Object*> v(_stuff.begin(), _stuff.end());
    auto random_engine = std::default_random_engine {};
    std::shuffle(std::begin(v), std::end(v), random_engine);
    stuff = std::list<Object*>(v.begin(), v.end());
    auto itStuff = stuff.begin();
    for (coord_t i = 0; i < N; ++i) {
        for (coord_t j = 0; j < M; ++j) {
            if((*itStuff)->getObjType() == ObjType::PREY)
                countPreyChange(1);
            if((*itStuff)->getObjType() == ObjType::PREDATOR)
                countPredatorChange(1);
            cells[i][j].setObject(*itStuff);
            cells[i][j].init({i,j},this);
            (*itStuff)->setCell(&cells[i][j]);
            itStuff++;
        }
    }
}

void Ocean::run(int numOfEpochs) {
    while (numOfEpochs--) {
        print();
        auto iter = stuff.begin();
        while (iter != stuff.end()) {
            if ((*iter)->isDead()) {
                delete *iter;
                iter = stuff.erase(iter);
            } else {
                (*iter)->live();
                ++iter;
            }
        }

        iter = objects_to_add.begin();
        while (iter != objects_to_add.end()) {
            if ((*iter)->isDead()) {
                delete *iter;
                iter = objects_to_add.erase(iter);
            } else {
                ++iter;
            }
        }
        stuff.merge(objects_to_add);
        objects_to_add.clear();
        if(getNumPredators() == 0) {
            print();
            std::cout << "The game is over: all predators are dead!\n";
            break;
        }
        if(getNumPreys() == 0) {
            print();
            std::cout << "The game is over: all preys are dead!\n";
            break;
        }
    }
}

Cell* Ocean::getCell(coord_t a, coord_t b) {
    return &cells[a][b];
}

void Ocean::addObject(Object *_stuff) {
    objects_to_add.push_back(_stuff);
}

void Ocean::countPreyChange(int i) {
    countPrey += i;
}

void Ocean::countPredatorChange(int i) {
    countPredator += i;
}

int Ocean::getNumPreys() const {
    return countPrey;
}

int Ocean::getNumPredators() const {
    return countPredator;
}
