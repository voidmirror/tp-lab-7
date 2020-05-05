//
// Created by Mikhail on 01.05.2020.
//

#include <cell.h>
#include <ocean.h>
#include <utility>

Cell::Cell(pair<int, int> _position, Ocean *_ocean) : position(std::move(_position)), ocean(_ocean) {}

void Cell::deleteObj() {
    if(object) {
        delete object;
        object = nullptr;
    }
}

Object *Cell::getObject() {
    return object;
}

pair<int, int> Cell::getPosition() {
    return position;
}

Ocean *Cell::getOcean() {
    return ocean;
}

void Cell::setObject(Object *_object) {
    object = _object;
}

vector<pair<int,int> > Cell::getNeighbours() {
    vector<pair<int,int> > neighbours;
    for (int i = 0; i < 4; i++) {
        int x = dx[i] + position.first, y = dy[i] + position.second;
        if (x < 0 || y < 0 || x >= ocean->getN() || y >= ocean->getM()) continue;
        neighbours.emplace_back(x, y);
    }
    return neighbours;
}

Cell::~Cell() {
    deleteObj();
};



