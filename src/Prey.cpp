#include "Prey.h"

Prey::Prey(): Object()
{
    this->objType = 1;
}

Cell* Prey::getFreeNearSpot(){
    std::vector<std::vector<Cell*>*> oceanMap = place->getOcean()->getMap();
    std::vector<Cell*> freeSpots;
    if(row + 1 <= oceanMap.size()-1 && oceanMap.at(row + 1)->at(col) != nullptr && (oceanMap.at(row + 1)->at(col))->isEmpty()){
        freeSpots.push_back(oceanMap.at(row + 1)->at(col));
    }
    if(col + 1 <= oceanMap.size()-1 &&oceanMap.at(row)->at(col + 1) != nullptr && (oceanMap.at(row)->at(col + 1))->isEmpty()){
        freeSpots.push_back(oceanMap.at(row)->at(col + 1));
    }
    if(row - 1 >= 0 && oceanMap.at(row - 1)->at(col) != nullptr && (oceanMap.at(row - 1)->at(col))->isEmpty()){
        freeSpots.push_back(oceanMap.at(row - 1)->at(col));
    }
    if(col - 1 >= 0 && oceanMap.at(row)->at(col - 1) != nullptr && (oceanMap.at(row)->at(col - 1))->isEmpty()){
        freeSpots.push_back(oceanMap.at(row)->at(col - 1));
    }
    if(freeSpots.size() == 0)
        return nullptr;
    if(freeSpots.size() == 1)
        return freeSpots.back();
    int randIndex = rand()%freeSpots.size();
    return freeSpots.at(randIndex);
}

void Prey::live(){
    std::vector<std::vector<Cell*>*> oceanMap = place->getOcean()->getMap();
    this->age++;
    Cell* freeSpot = getFreeNearSpot();
    if(freeSpot != nullptr){
        (oceanMap.at(row)->at(col))->setObject(nullptr);
        freeSpot->setObject(this);
    }
    if(age % 3 == 0){
        freeSpot = getFreeNearSpot();
            if(freeSpot != nullptr){
                Prey* child = new Prey();
                freeSpot->setObject(child);
                place->getOcean()->addObject(child);
        }
    }
    if(age >= 10){
        (oceanMap.at(row)->at(col))->setObject(nullptr);
        this->kill();
    }
}
