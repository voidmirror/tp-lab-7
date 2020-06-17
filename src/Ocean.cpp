//
// Created by Ivan Razzhivin  on 15.05.2020.
//

#include <values.h>
#include "../include/Ocean.h"
#include <unistd.h>

void Ocean::startGame() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    auto rng = std::default_random_engine (seed);
    auto turn = 0;
    while (true){
        std::shuffle(randomPoints.begin(), randomPoints.end(), rng);
        std::cout << "Step " << ++turn<<std::endl;
        for(auto i = 0; i < n; i++){
            for(auto j = 0; j < m; j++){
                auto obj = field[i][j]->getObject();
                std::cout << (obj? obj->getType() : EMPTY_N)  << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "Now alive:" << std::endl;
        std::cout << "Prey: " << additionalInfoMap[PREY_N].alive << std::endl;
        std::cout << "Predator: " << additionalInfoMap[PREDATOR_N].alive << std::endl;
        if (additionalInfoMap[PREY_N].alive == 0 || additionalInfoMap[PREDATOR_N].alive == 0){
            std::cout << "Game over" << std::endl;
            return;
        }
        for (auto&p : randomPoints){
            if (!madeMove[p.y][p.x]) {
                signal(field[p.y][p.x]);
            }
        }
        std::cout << std::endl;

        for (auto i = 0; i < n;i++){
            for (auto j = 0; j < n; j++){
                madeMove[i][j] = false;
            }
        }

        sleep(delay);
    }

}

Ocean::Ocean(size_t _n, size_t _m) {
    n = _n;
    m = _m;
    field = new Cell **[_n];
    madeMove = new bool*[_n];

    for (auto i=0; i < _n; i++){
        field[i] = new Cell*[_m];
        madeMove[i] = new bool[m];

        for (auto j=0; j < _m; j++){
            Pair p (j,i);

            field[i][j] = new Cell(p, this,  getRandomObject());
            madeMove[i][j] = false;
            randomPoints.emplace_back(p);
        }
    }
}

Ocean::~Ocean(){
    for(int i=0; i<m; i++)
    {
        delete []field[i];
    }
    delete []field;
}

Cell *Ocean::findNewCellAround(Pair p, Object* finder) {
    auto numSides = 4;
    auto randomSide = random() % numSides;
    auto start = 0;
    for (auto i = randomSide; i < numSides; i = (i+1) % numSides){
        if (start >= numSides) break;
        start++;
        switch (i){
            case LEFT:
                if (isCellBelows(p.x - 1,p.y) &&
                (field [p.y][p.x - 1]->getObject() == nullptr || additionalInfoMap[field [p.y][p.x - 1]->getObject()->getType()].hierarchy < additionalInfoMap[finder->getType()].hierarchy)){
                    return field [p.y][p.x - 1];
                }
            case UP:
                if (isCellBelows(p.x, p.y + 1) &&
                (field [p.y + 1][p.x]->getObject() == nullptr || additionalInfoMap[field [p.y + 1][p.x]->getObject()->getType()].hierarchy < additionalInfoMap[finder->getType()].hierarchy)){
                    return field [p.y + 1][p.x];
                }
            case RIGHT:
                if (isCellBelows(p.x + 1, p.y) &&
                (field [p.y][p.x + 1]->getObject() == nullptr || additionalInfoMap[field [p.y][p.x + 1]->getObject()->getType()].hierarchy < additionalInfoMap[finder->getType()].hierarchy)){
                    return field [p.y][p.x + 1];
                }
            case DOWN:
                if (isCellBelows(p.x, p.y - 1 ) &&
                (field [p.y - 1 ][p.x]->getObject() == nullptr || additionalInfoMap[field [p.y - 1][p.x]->getObject()->getType()].hierarchy < additionalInfoMap[finder->getType()].hierarchy)){
                    return field [p.y - 1 ][p.x];
                }
            default:
                continue;
        }
    }
    return nullptr;
}

bool Ocean::isCellBelows(size_t x, size_t y) {
    return (x >= 0) && (y >= 0) && (x < m) && (y < n);
}

Object *Ocean::getRandomObject() {
    unsigned int rand = random() % 100;
    if ((0 <= rand)&& (rand < 5)){
        return new Stone();
    }else if ((5 <= rand)&& (rand < 25)){
        return new Predator();
    }else if ((25 <= rand)&& (rand < 55)){
        return new Prey();
    }
    return nullptr; 
}

std::map<char, AliveAndHierarchy>* Ocean::getAdditionalInfoMap(){
    return &additionalInfoMap;
}


void Cell::setObject(Object* _object) {
    if ((getObject() == nullptr) && (_object != nullptr)) {
        (*getOcean()->getAdditionalInfoMap())[EMPTY_N].alive--;
        (*getOcean()->getAdditionalInfoMap())[_object->getType()].alive++;
        _object->setMyCell(this);
    }else if ((getObject() != nullptr) && (_object == nullptr)) {
        (*getOcean()->getAdditionalInfoMap())[getObject()->getType()].alive--;
        (*getOcean()->getAdditionalInfoMap())[EMPTY_N].alive++;
    }else if ((getObject() != nullptr) && (_object != nullptr)){
        (*getOcean()->getAdditionalInfoMap())[getObject()->getType()].alive--;
        (*getOcean()->getAdditionalInfoMap())[_object->getType()].alive++;

    }
    object = _object;
}

void Cell::setOcean(Ocean *_ocean) {
    ocean = _ocean;
}

void Cell::setCoords(Pair _coords) {
    coords = _coords;
}

Cell::Cell(Pair coords, Ocean *ocean, Object *object){
    this->setCoords(coords);
    this->setOcean(ocean);
    this->setObject(object);
}

const Pair &Cell::getCoords() const {
    return coords;
}

Object *Cell::getObject() const {
    return object;
}

Ocean *Cell::getOcean() const {
    return ocean;
}

void signal(Cell * c) {
    if (c->object == nullptr){
        return;
    }
    c->object->live();
}