#ifndef OCEAN_H
#define OCEAN_H

#include <vector>
#include <iostream>

#include "Cell.h"
#include "Object.h"

class Ocean
{
    public:
        Ocean(int mapSize);
        void dispMap();
        void createCreatures(int stones, int preys, int predators);
        void startSim();
        Cell* getCell(int row, int col){return oceanMap.at(row)->at(col);};
        std::vector<std::vector<Cell*>*> getMap(){return this->oceanMap;};
        void addObject(Object* newFish){bornQueue.push_back(newFish);};
        Object* getLastCreat(){return creatures.back();};
        void bornAll();
    protected:

    private:
        std::vector<Object*> creatures;
        std::vector<Object*> bornQueue;
        Cell* genRandEmptyCell();
        int mapSize;
        int preyCount;
        int predCount;
        std::vector<std::vector<Cell*>*> oceanMap;

};

#endif // OCEAN_H
