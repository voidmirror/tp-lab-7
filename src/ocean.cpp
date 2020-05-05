//
// Created by Mikhail on 01.05.2020.
//
#include <ocean.h>
#include <stone.h>
#include <prey.h>
#include <predator.h>
#include <ctime>
#include <afxres.h>

using std::cout;

void Ocean::addObject(Object *object) {
    stuff.insert(object);
}

int Ocean::getN() {
    return n;
}

int Ocean::getM() {
    return m;
}

Cell *Ocean::getCell(int i, int j) {
    return cells[i][j];
}

void Ocean::swap(pair<int, int> f , pair<int, int> s) {
    Cell* buf = cells[f.first][f.second];
    cells[f.first][f.second] = cells[s.first][s.second];
    cells[s.first][s.second] = buf;
    pair<int,int> coords = cells[f.first][f.second]->position;
    cells[f.first][f.second]->position = cells[s.first][s.second]->position;
    cells[s.first][s.second]->position = coords;
}

void Ocean::fill(pair<int, int> point) {
    used[point.first][point.second] = true;
}

bool Ocean::notUsed(pair<int, int> point) {
    return used[point.first][point.second];
}

void Ocean::deleteObj(Cell *cell) {
    stuff.erase(cell->getObject());
    cell->deleteObj();
}

void Ocean::addObjects(ObjType objType, int number) {
    srand(time(0));

    if (ObjType::PREY == objType) {
        for(int i = 0; i < number; i++) {
            int x = rand() % n;
            int y = rand() % m;
            int it = 0;
            while (cells[x][y]->getObject() && it < n * m) {
                x = rand() % n;
                y = rand() % m;
                it++;
            }
            if(it != n * m) {
                Prey* object = new Prey(cells[x][y]);
                cells[x][y]->setObject(object);
                stuff.insert(object);
            }
        }
    }

    if (ObjType::PREDATOR == objType) {
        for(int i = 0; i < number; i++) {
            int x = rand() % n;
            int y = rand() % m;
            int it = 0;
            while (cells[x][y]->getObject() && it < n * m) {
                x = rand() % n;
                y = rand() % m;
                it++;
            }
            if(it != n * m) {
                Predator* object = new Predator(cells[x][y]);
                cells[x][y]->setObject(object);
                stuff.insert(object);
            }
        }
    }

    if (ObjType::STONE == objType) {
        for(int i = 0; i < number; i++) {
            int x = rand() % n;
            int y = rand() % m;
            int it = 0;
            while (cells[x][y]->getObject() && it < n * m) {
                x = rand() % n;
                y = rand() % m;
                it++;
            }
            if(it != n * m) {
                Stone* object = new Stone(cells[x][y]);
                cells[x][y]->setObject(object);
                stuff.insert(object);
            }
        }
    }
}

void Ocean::print() {
    system("cls");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            auto object = cells[i][j]->getObject();
            if (object) {
                if(object->getType() == ObjType::STONE) cout << STONE_N;
                if(object->getType() == ObjType::PREDATOR) cout << PREDATOR_N;
                if(object->getType() == ObjType::PREY) cout << PREY_N;
            }
            else cout << '.';
        }
        cout << '\n';
    }
}

void Ocean::live(int iterations) {
    for(int it = 0; it < iterations; it++) {
        for(int i = 0; i < n; i++) for (int j = 0; j < m; j++) used[i][j] = false;
        set<Object* > onDelete;
        for(auto* object: stuff) {
            if(!object) {
                onDelete.insert(object);
                continue;
            }
            if(!object->live())
                onDelete.insert(object);
        }
        for(auto* object: onDelete) {
            if(object) {
                deleteObj(object->getCell());
            }
            else {
                stuff.erase(object);
            }
        }
        print();
        Sleep(30);
    }
}

Ocean::Ocean(int _n, int _m) : n(_n), m(_m) {
    cells.resize(n);
    used.resize(n);
    for (int i = 0; i < n; i++) {
        cells[i].resize(m);
        for (int j = 0; j < m; j++) {
            cells[i][j] = new Cell({i, j}, this);
        }
        used[i].resize(m, false);
    }
}
