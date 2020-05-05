#include "ocean.h"
#include "cell.h"
#include <random>
#include <algorithm>

using namespace std;

Ocean::Ocean(int size_x, int size_y) {
    oceanSize.x = size_x;
    oceanSize.y = size_y;
    cells.resize(oceanSize.x);
    for (int i = 0; i < oceanSize.x; i++) {
        cells[i].resize(oceanSize.y);
        for (int j = 0; j < oceanSize.y; j++) {
            cells[i][j] = new Cell();
            cells[i][j]->init(i, j, this);
        }
    }
}

void Ocean::print() {
    for (int i = 0; i < oceanSize.x; i++) {
        for (int j = 0; j < oceanSize.y; j++) {
            if (cells[i][j]->getObject()) {
                cout << cells[i][j]->getObject()->getChar() << " ";
            } else {
                cout << ". ";
            }
        }
        cout << "\n";
    }
}

void Ocean::addObjects(ObjType type, int num) {
    for (int i = 0; i < num;) {
        int x = rand() % oceanSize.x;
        int y = rand() % oceanSize.y;
        if (cells[x][y]->getObject())
            continue;
        Object *obj = nullptr;
        switch (type) {
            case ObjType::PREY :
                obj = new Prey(cells[x][y]);
                break;
            case ObjType::PREDATOR :
                obj = new Predator(cells[x][y]);
                break;
            case ObjType::STONE :
                obj = new Stone(cells[x][y]);
                break;
            default:
                break;
        }
        cells[x][y]->setObject(obj);
        stuff.push_back(obj);
        i++;
    }
}

void Ocean::addStuff(Object *obj) {
    stuff.push_back(obj);
}

void Ocean::live(int numOfIter) {
    for (int i = 0; i < numOfIter; i++) {
        list<Object *> livingStuff;
        for (auto obj : stuff) {
            if (!(obj->live())) {
                obj->getCell()->setObject(nullptr);
                obj = nullptr;
            } else
                livingStuff.push_back(obj);
        }
        int nPredator = 0, nPrey = 0;
        stuff = livingStuff;
        for (auto obj : livingStuff) {
            if (obj->getObjType() == ObjType::PREDATOR)
                nPredator++;
            else if (obj->getObjType() == ObjType::PREY)
                nPrey++;
        }
        if (nPredator == 0) {
            print();
            cout << "Predators starved to death" << endl;
            return;
        }
        if (nPrey == 0) {
            print();
            cout << "Prey fish eaten by predators" << endl;
            return;
        }
    }
    print();
    cout << "There are both predators and prey in the ocean" << endl;
}

Cell *Ocean::preyCell(Pair coords) {
    vector<pair<size_t, size_t>> pos_coords = {
            make_pair(coords.x + 1, coords.y),
            make_pair(coords.x - 1, coords.y),
            make_pair(coords.x, coords.y + 1),
            make_pair(coords.x, coords.y - 1)};
    for (auto i : pos_coords) {
        if ((i.first >= 0) && (i.first < oceanSize.x) &&
            (i.second >= 0) && (i.second < oceanSize.y)) {
            if (cells[i.first][i.second]->getObject()) {
                if (cells[i.first][i.second]->getObject()->getObjType() == ObjType::PREY)
                    return cells[i.first][i.second];
            }
        }
    }
    return nullptr;
}

Cell *Ocean::emptyCell(Pair coords) {
    vector<pair<size_t, size_t>> pos_coords = {
            make_pair(coords.x + 1, coords.y),
            make_pair(coords.x - 1, coords.y),
            make_pair(coords.x, coords.y + 1),
            make_pair(coords.x, coords.y - 1)};
    auto rng = default_random_engine{};
    shuffle(pos_coords.begin(), pos_coords.end(), rng);
    for (auto i : pos_coords) {
        if ((i.first >= 0) && (i.first < oceanSize.x) && (i.second >= 0) && (i.second < oceanSize.y)) {
            if (cells[i.first][i.second]->getObject() == nullptr) {
                return cells[i.first][i.second];
            }
        }
    }
    return nullptr;
}