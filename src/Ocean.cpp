#include "Ocean.h"
#include "Predator.h"
#include "Stone.h"
#include "Prey.h"
#include <unistd.h>

Ocean::Ocean(int mapSize)
{
    this->mapSize = mapSize;
    for(int i = 0; i < mapSize; i++){
        oceanMap.push_back(new std::vector<Cell*>());
        for(int o = 0; o < mapSize; o++){
            oceanMap.back()->push_back(new Cell(this));
            oceanMap.back()->back()->setRow(i);
            oceanMap.back()->back()->setCol(o);
        }
    }
}

Cell* Ocean::genRandEmptyCell(){
    Cell* result = oceanMap.at(rand() % mapSize)->at(rand() % mapSize);
    while(!result->isEmpty()){
        result = oceanMap.at(rand() % mapSize)->at(rand() % mapSize);
    }
    return result;
}

void Ocean::createCreatures(int stones, int preys, int predators){
    if(stones + preys + predators > mapSize * mapSize){
        return;
    }
    Cell* place;
    preyCount = preys;
    predCount = predators;
    for(int i = 0; i < stones; i++){
        place = genRandEmptyCell();
        creatures.push_back(new Stone());
        place->setObject(creatures.back());
        creatures.back()->setPlace(place);
        /*creatures.back()->setRow(place->getRow());
        creatures.back()->setCol(place->getCol());*/
    }
    for(int i = 0; i < preys; i++){
        place = genRandEmptyCell();
        creatures.push_back(new Prey());
        place->setObject(creatures.back());
        creatures.back()->setPlace(place);
        /*creatures.back()->setRow(place->getRow());
        creatures.back()->setCol(place->getCol());*/
    }
    for(int i = 0; i < predators; i++){
        place = genRandEmptyCell();
        creatures.push_back(new Predator());
        place->setObject(creatures.back());
        creatures.back()->setPlace(place);
        /*creatures.back()->setRow(place->getRow());
        creatures.back()->setCol(place->getCol());*/
    }
}

void Ocean::dispMap(){
    Cell* curCell;
    for(int i = 0; i < mapSize; i++){
        for(int o = 0; o < mapSize; o++){
            curCell = oceanMap.at(i)->at(o);
            switch (curCell->getObjType()){
                case 0:
                    std::cout << "0";
                    break;
                case 1:
                    std::cout << "f";
                    break;
                case 2:
                    std::cout << "F";
                    break;
                default:
                    std::cout << ".";
            }
        }
        std::cout << std::endl;
    }
}

void Ocean::bornAll(){
    std::vector<Object*>::iterator i = bornQueue.begin();
    std::vector<Object*>::iterator v = bornQueue.end();
    while(i != v){
        creatures.push_back(*i);
        if((*i)->getObjType() == 1){
            preyCount++;
        }else{
            predCount++;
        }
        ++i;
    }
    if(bornQueue.size() != 0)
    bornQueue.clear();
}

void Ocean::startSim(){
    while(true){
        usleep(100000);
        std::vector<Object*>::iterator temp = creatures.begin();
        std::vector<Object*>::iterator i = creatures.begin();
        std::vector<Object*>::iterator tail = creatures.end();
        while (i < tail){
             if((*i)->checkKilled()){
                if((*i)->getObjType() == 1){
                    ++i;
                    creatures.erase(i-1);
                    this->preyCount--;
                }else{
                    ++i;
                    creatures.erase(i-1);
                    this->predCount--;
                }
            }else{
                (*i)->live();
                ++i;
            }
            tail = creatures.end();
        }
        std::cout << "\nPreys: " << preyCount << " Predators: " << predCount << std::endl;
        bornAll();
        dispMap();
        if((predCount == 0 || preyCount == 0) || creatures.size() > (mapSize * mapSize)){
            break;
        }
    }
}
