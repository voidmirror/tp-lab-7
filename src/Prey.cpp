//
// Created by iddoroshenko on 26.03.2020.
//

#include <random>
#include <algorithm>
#include "Prey.h"
#include "Predator.h"

void Prey::move() {
    std::vector<std::pair<int,int>> moveList = {{0,1}, {1,0}, {-1,0}, {0, -1}};
    auto random_engine = std::default_random_engine {};
    std::shuffle(std::begin(moveList), std::end(moveList), random_engine);
    for(int i = 0; i < 4; i++) {
        int x = static_cast<int>(cell->getCrd().x) + moveList[i].first;
        int y = static_cast<int>(cell->getCrd().y) + moveList[i].second;
        if(x < N && 0 <= x && y < M && 0 <= y) {
            Object* object = cell->getOcean()->getCell(x,y)->getObject();
            if(object->getObjType() == ObjType::CORAL) {
                cell->getOcean()->getCell(x,y)->killMe();
                object->killObj();
                Object* coral = new Coral();
                coral->setCell(cell);
                cell->setObject(coral);
                cell->getOcean()->addObject(coral);
                cell->getOcean()->getCell(x,y)->setObject(this);
                setCell(cell->getOcean()->getCell(x,y));
            }
        }
    }
}
void Prey::live()  {
    liveTime--;
    if(liveTime == 0) {
        killObj();
        cell->getOcean()->countPreyChange(-1);
        Object* coral = new Coral();
        cell->setObject(coral);
        cell->getOcean()->addObject(coral);
        return;
    }
    int m = rand() % 2;
    if (m) {
        move();
    } else {
        reproduce(ObjType::PREY);
    }
}

void Prey::reproduce(ObjType objType) {
    std::vector<std::pair<int,int>> moveList = {{0,1}, {1,0}, {-1,0}, {0, -1}};
    auto random_engine = std::default_random_engine {};
    std::shuffle(std::begin(moveList), std::end(moveList), random_engine);
    for(int i = 0; i < 4; i++) {
        int x = static_cast<int>(cell->getCrd().x) + moveList[i].first;
        int y = static_cast<int>(cell->getCrd().y) + moveList[i].second;
        if(x < N && 0 <= x && y < M && 0 <= y) {
            Object* object = cell->getOcean()->getCell(x,y)->getObject();
            if(object->getObjType() == ObjType::CORAL) {
                if(objType == ObjType::PREY) {
                    object->killObj();
                    Object *prey = new Prey();
                    prey->setCell(cell->getOcean()->getCell(x,y));
                    cell->getOcean()->getCell(x,y)->killMe();
                    cell->getOcean()->getCell(x,y)->setObject(prey);
                    cell->getOcean()->addObject(prey);
                    cell->getOcean()->countPreyChange(1);
                }
                if(objType == ObjType::PREDATOR) {
                    object->killObj();
                    Object *prey = new Predator();
                    prey->setCell(cell->getOcean()->getCell(x,y));
                    cell->getOcean()->getCell(x,y)->killMe();
                    cell->getOcean()->getCell(x,y)->setObject(prey);
                    cell->getOcean()->addObject(prey);
                    cell->getOcean()->countPredatorChange(1);
                }
            }
        }
    }
}


