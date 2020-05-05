//
// Created by Mikhail on 01.05.2020.
//

#ifndef TASK1_CELL_H
#define TASK1_CELL_H

#include <iostream>
#include <vector>
#include <helpers.h>


using std::pair;
using std::vector;

class Ocean;
class Object;

class Cell {
    friend Ocean;
private:
    pair<int, int> position;
    Object* object{};
    Ocean* ocean;
public:
    Cell(pair<int, int>, Ocean*);
    Object* getObject();
    pair<int, int> getPosition();
    Ocean* getOcean();
    void setObject(Object*);
    void deleteObj();
    vector<pair<int,int> > getNeighbours();
};
#endif //TASK1_CELL_H
