//
// Created by Оксана on 19.04.2020.
//
#include <iostream>
#include <ocean.h>
#include <common.h>
#include <stone.h>
#include <prey.h>
#include <predator.h>
#include <cell.h>
using namespace std;


Ocean::Ocean()
{
    cells.resize(N);
    for (size_t x = 0; x < N; x++)
    {
        cells[x].resize(M);
        for (size_t y = 0; y < M; y++)
            cells[x][y].init({ x, y }, this);
    }
    sizeOfOcean = {N, M};
}

Ocean::~Ocean() {
    for (auto object : creatures)
        delete object;
}

void Ocean::addObject(Object* object){
    creatures.push_back(object);
}

void Ocean::addObjects(ObjType type, int amount){
    int cnt = 0;
    while (cnt < amount)
    {
        int x = rand() % N;
        int y = rand() % M;
        if (cells[x][y].getObject() == nullptr)
        {
            Object* sea_creature = nullptr;
            switch (type)
            {
                case ObjType::PREDATOR:
                    sea_creature = new Predator(&cells[x][y]);
                    break;
                case ObjType::PREY:
                    sea_creature = new Prey(&cells[x][y]);
                    break;
                case ObjType::STONE:
                    sea_creature = new Stone(&cells[x][y]);
                    break;
            }
            cells[x][y].setObject(sea_creature);
            creatures.push_back(sea_creature);
            cnt++;
        }
    }

}



Cell* Ocean::getCellByName(Pair coord, ObjType type){
    Pair possible;
    int flag = 0;

    Pair nearCells[8] =  {{ coord.x, coord.y + 1 },
                        { coord.x + 1, coord.y + 1 },
                        { coord.x + 1, coord.y},
                        { coord.x + 1, coord.y - 1 },
                        { coord.x, coord.y - 1 },
                        { coord.x - 1, coord.y - 1 },
                        { coord.x - 1, coord.y},
                        { coord.x - 1, coord.y + 1 }};

    for (const auto &coord : nearCells)
    {
        if ((coord.x < sizeOfOcean.first) && (coord.y < sizeOfOcean.second) && coord.x >= 0 && coord.y >= 0)
        {
            if (cells[coord.x][coord.y].getObject() && cells[coord.x][coord.y].getObject()->getObjectType() == type)
            {
                possible = coord;
                flag = 1;
                break;
            }
        }
    }

    if (flag) return &cells[possible.x][possible.y];
    else return nullptr;
}

Cell* Ocean::getEmptyCellByName(Pair coord){
    Pair possible;
    int flag = 0;

    Pair nearCells[8] =  {{ coord.x, coord.y + 1 },
                          { coord.x + 1, coord.y + 1 },
                          { coord.x + 1, coord.y},
                          { coord.x + 1, coord.y - 1 },
                          { coord.x, coord.y - 1 },
                          { coord.x - 1, coord.y - 1 },
                          { coord.x - 1, coord.y},
                          { coord.x - 1, coord.y + 1 }};

    for (const auto &coord : nearCells)
    {
        if ((coord.x < sizeOfOcean.first) && (coord.y < sizeOfOcean.second) && coord.x >= 0 && coord.y >= 0)
        {
            if (cells[coord.x][coord.y].getObject() == nullptr)
            {
                possible = coord;
                flag = 1;
                break;
            }
        }
    }

    if (flag) return &cells[possible.x][possible.y];
    else return nullptr;
}




void Ocean::print() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            Object* object = cells[i][j].getObject();
            if (!object) {
                cout << ".";
            }
            else {
                cout << object->getSymb();
            }
        }
        cout << '\n';
    }
    for (int i = 0; i < N; i++)cout << "=";
    cout << '\n';
}


Cell* Ocean::getCell(coord_t x, coord_t y){
    return &cells[x][y];
};


bool Ocean::deleteObject(Cell* cell){
    Object* deletethis = cell->getObject();
    for (auto obj_it = creatures.begin(); obj_it != creatures.end(); obj_it++){
        if ((*obj_it) == deletethis){
            creatures.erase(obj_it);
            deletethis->getCell()->setObject(nullptr);
            return true;
        }
    }
    return false;
}

void Ocean::run(size_t iter){
    while (iter)
    {
        print();
        for (auto i = creatures.begin(); i != creatures.end(); i++)

            (*i)->live();
        iter -= 1;
    }
}