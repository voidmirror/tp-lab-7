#include "Predator.h"

Predator::Predator()
{
    this->objType = 2;
    this->preysInside = 0;
    this->age = 0;

}

Cell* Predator::findPreyNear(){
    std::vector<std::vector<Cell*>*> oceanMap = place->getOcean()->getMap();
    std::vector<Cell*> preys;
    if(row + 1 <= oceanMap.size()-1 && oceanMap.at(row + 1)->at(col) != nullptr && (oceanMap.at(row + 1)->at(col))->getObjType() == 1){
        preys.push_back(oceanMap.at(row + 1)->at(col));
    }
    if(col + 1 <= oceanMap.size()-1 &&oceanMap.at(row)->at(col + 1) != nullptr && (oceanMap.at(row)->at(col + 1))->getObjType() == 1){
        preys.push_back(oceanMap.at(row)->at(col + 1));
    }
    if(row - 1 >= 0 && oceanMap.at(row - 1)->at(col) != nullptr && (oceanMap.at(row - 1)->at(col))->getObjType() == 1){
        preys.push_back(oceanMap.at(row - 1)->at(col));
    }
    if(col - 1 >= 0 && oceanMap.at(row)->at(col - 1) != nullptr && (oceanMap.at(row)->at(col - 1))->getObjType() == 1){
        preys.push_back(oceanMap.at(row)->at(col - 1));
    }
    if(preys.size() == 0)
        return nullptr;
    if(preys.size() == 1)
        return preys.back();
    int randIndex = rand()%preys.size();
    return preys.at(randIndex);
}

void Predator::live(){
    std::vector<std::vector<Cell*>*> oceanMap = place->getOcean()->getMap();
    Cell* spot = findPreyNear();
    if(spot != nullptr){
        (spot->getObject())->kill();
        preysInside++;
        (oceanMap.at(row)->at(col))->setObject(nullptr);
        spot->setObject(this);
        if(preysInside >= 2){
            spot = getFreeNearSpot();
            if(spot != nullptr){
                preysInside--;
                Predator* child = new Predator();
                spot->setObject(child);
                place->getOcean()->addObject(child);
            }
        }
    }else{
        preysInside--;
        spot = getFreeNearSpot();
        if(spot != nullptr){
            (oceanMap.at(row)->at(col))->setObject(nullptr);
            spot->setObject(this);
        }
    }
    age++;
    if(age == 15 || preysInside == -3){
        std::cout << "Pk ";
        (oceanMap.at(row)->at(col))->setObject(nullptr);
        this->kill();
    }
}
