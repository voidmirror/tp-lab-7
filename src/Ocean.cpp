//
// Created by aklen on 23.04.2020.
//
#include "Ocean.h"
#include "Cell.h"
#include "Object.h"

int dx[8] = { 0, 0, -1, -1, -1, 1, 1, 1};
int dy[8] = { -1, 1, 0, 1, -1, 0, 1, -1};


Ocean::Ocean(Pair p) {
    cells = new Cell*[p.y];
    for(int i=0; i < p.y; i++){
        cells[i] = new Cell[p.x];
        for(int j=0; j < p.x; j++){
            cells[i][j].initObj({i,j}, this);
        }
    }
    ocean_size = {p.x, p.y};
    busy_cells_counter = 0;
}


Ocean::~Ocean() {
    for(int i(0); i < ocean_size.y; i++){
        delete cells[i];
    }
    delete cells;

    for(auto obj : stuff){
        delete obj;
    }
}


void Ocean::addStuff(Object* obj){
    this->stuff.push_back(obj);
    busy_cells_counter += 1;
}


void Ocean::addObjects(ObjType type, int number) {
    for (int i = 0; i < number; i++) {
        int count = 0;
        int x = rand() % ocean_size.x;
        int y = rand() % ocean_size.y;
        while (cells[x][y].getObject() != nullptr && count < ocean_size.x * ocean_size.y) {
            x = rand() % ocean_size.x;
            y = rand() % ocean_size.y;
            count++;
        }
        Object *object = nullptr;
        if (count == ocean_size.x * ocean_size.y) {
            for (int j = 0; j < ocean_size.y; j++)
                for (int k = 0; k < ocean_size.x; k++) {
                    if (cells[j][k].getObject() == nullptr) {
                        switch (type) {
                            case ObjType::PREDATOR:
                                object = new Predator(&cells[j][k]);
                                break;
                            case ObjType::PREY:
                                object = new Prey(&cells[j][k]);
                                break;
                            case ObjType::STONE:
                                object = new Stone(&cells[j][k]);
                                break;
                            default:
                                break;
                        }
                        this->addStuff(object);
                        cells[j][k].setObject(object);
                    }
                }
        }
        else{
            switch (type) {
                case ObjType::PREDATOR:
                    object = new Predator(&cells[x][y]);
                    break;
                case ObjType::PREY:
                    object = new Prey(&cells[x][y]);
                    break;
                case ObjType::STONE:
                    object = new Stone(&cells[x][y]);
                    break;
                default:
                    break;
            }
            this->addStuff(object);
            cells[x][y].setObject(object);
        }
    }
}


void Ocean::deleteObject(Object * object) {
    object->getCell()->kill();
}


void Ocean::print()const{
    for(int i=0; i<ocean_size.y; i++){
        for(int j=0; j<ocean_size.x; j++){
            cout<< (cells[i][j].getObject() ? cells[i][j].getObject()->getSymbol() : '.');
        }
        cout << endl;
    }
}


void Ocean::live(int iter){
    for(int j = 0; j<iter; j++) {
        for (auto i = stuff.begin(); i != stuff.end(); i++) {
            if (!(*i)->live()) {
                deleteObject(*i);
                stuff.erase(i++);
            }
        }
        this->print();
        cout << "\n\n" << endl;
    }
}


Cell* Ocean::search_empty(Pair coord) {
    for(int i = 0; i < 8; i++){
        int new_x = coord.x + dx[i];
        int new_y = coord.y + dy[i];
        if(new_x >= 0 && new_y >=0 && new_x < ocean_size.x && new_y < ocean_size.y)
            if(cells[new_y][new_x].getObject() == nullptr )
                return &cells[new_y][new_x];
    }
    return nullptr;
}


Cell* Ocean::search_prey(Pair coord) {
    for(int i = 0; i < 8; i++){
        int new_x = coord.x + dx[i];
        int new_y = coord.y + dy[i];
        if(new_x >= 0 && new_y >=0 && new_x < ocean_size.x && new_y < ocean_size.y)
            if(cells[new_y][new_x].getObject() && cells[new_y][new_x].getObject()->getType() == ObjType::PREY )
                return &cells[new_y][new_x];
    }
    return nullptr;
}

