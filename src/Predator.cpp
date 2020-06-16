//
// Created by iddoroshenko on 28.04.2020.
//

#include <random>
#include <algorithm>
#include "Predator.h"

bool Predator::eat() {
    std::vector<std::pair<int,int>> moveList = {{0,1}, {1,0}, {-1,0}, {0, -1}};
    auto random_engine = std::default_random_engine {};
    std::shuffle(std::begin(moveList), std::end(moveList), random_engine);
    for(int i = 0; i < 4; i++) {
        int x = static_cast<int>(cell->getCrd().x) + moveList[i].first;
        int y = static_cast<int>(cell->getCrd().y) + moveList[i].second;
        if(x < N && 0 <= x && y < M && 0 <= y) {
            Object* object = cell->getOcean()->getCell(x,y)->getObject();
            if(object->getObjType() == ObjType::PREY) {
                object->killObj();
                cell->getOcean()->getCell(x,y)->killMe();
                Object* coral = new Coral();
                coral->setCell(cell);
                cell->setObject(coral);
                cell->getOcean()->addObject(coral);
                cell->getOcean()->getCell(x,y)->setObject(this);
                setCell(cell->getOcean()->getCell(x,y));
                hungry = 3;
                cell->getOcean()->countPreyChange(-1);
                return true;
            }
        }
    }
    return false;
}

void Predator::live() {
    liveTime--;
    hungry--;
    if(liveTime == 0 || hungry == -3) {
        cell->getOcean()->countPredatorChange(-1);
        killObj();
        Object* coral = new Coral();
        cell->getOcean()->addObject(coral);
        cell->setObject(coral);
        return;
    }
    if(hungry > 0) {
        int m = rand() % 2;
        if (m) {
            move();
        } else {
            reproduce(ObjType::PREDATOR);
        }
    } else {
        if(eat()) {
            hungry = 3;
        }
    }

}

