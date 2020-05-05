#include "Ocean.hpp"
#include "Cell.hpp"
#include "Defaults.h"
#include "Object.hpp"

#include <random>
#include <iostream>

using namespace std;

Ocean::Ocean() {
    cells = new Cell*[X];
    for (size_t i = 0; i < X; i++) {
        cells[i] = new Cell[Y];
        for (size_t j= 0; j < Y; j++)
            cells[i][j].init({i, j}, this);
    }
}


Ocean::~Ocean() {
    for (int i = 0; i < X; i++)
        delete[] cells[i];

    delete[] cells;
    for (auto creature : creatures)
        delete creature;
}


int* Ocean::print() const {
    int preys = 0;
    int predators = 0;
    int stones = 0;
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++)  {
            if (cells[i][j].getObject() != nullptr) {
                ObjType stuff = cells[i][j].getObject()->getType();
                switch (stuff) {
                    case 'S':
                        predators++;
                        break;
                    case 'f':
                        preys++;
                        break;
                    case '#':
                        stones++;
                        break;
                    default:
                        break;
                }
                cout << stuff << " ";
            }
            else {
                cout << ". ";
            }
        }
        cout << endl;
    }
}

void Ocean::addObj(ObjType type, unsigned int value) {
        for (int i = 0; i < value; i++) {
            auto x = rand() % X;
            auto y = rand() % Y;
            Object* object = nullptr;
            if (this->cells[x][y].getObject()) {
                i -= 1;
            }
            switch(type){
                case ObjType::PREY:
                    object = new Prey(&this->cells[x][y]);
                    break;
                case ObjType::PREDATOR:
                    object = new Predator(&this->cells[x][y]);
                    break;
                case ObjType::STONE:
                    object = new Stone(&this->cells[x][y]);
                    break;
                default:
                    break;
            }
            this->cells[x][y].setObject(object);
            produceObj(object);
        }
    }


void Ocean::produceObj(Object *obj){
    this->creatures.push_back(obj);
}

void Ocean::killObj(Object *obj)
{
    obj->getCell()->killObject();
}

Cell* Ocean::findPrey(Coord crd) const {
    for (int i(0); i < PREY_TRIES; i++) {
        size_t x = crd.x + rand() % 3 - 1;
        size_t y = crd.y + rand() % 3 - 1;
        if (x < X && y < Y)
            if (cells[x][y].getObject() && cells[x][y].getObject()->getType() == ObjType::PREY)
                return &cells[x][y];
    }
    return nullptr;
}
Cell* Ocean::findCell(Coord crd) {
    for(int i = 0; i < CELL_TRIES; i ++){
        size_t x = crd.x + rand() % 3 - 1;
        size_t y = crd.y + rand() % 3 - 1;
        if (x < X && y < Y)
            if (cells[x][y].getObject() == nullptr)
                return &cells[x][y];
    }
    return nullptr;
}

void Ocean::run() {
    for(auto i = creatures.begin(); i != creatures.end();i++){
        if((*i)->live() == false){
            killObj(*i);
            creatures.erase(i++);
        }
    }
} 
