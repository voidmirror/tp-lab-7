#ifndef OCEAN_H
#define OCEAN_H

#include "common.h"
#include "Cell.h"
#include "Stone.h"

class Ocean
{
    friend Cell;
private:
    Cell** cells;
    size_t N, M;
    std::list<Object*> objects;
    int countPrey = 0, countPredator = 0, countStone = 0;
public:
    Ocean(size_t, size_t, int, int, int);
    ~Ocean();
    void print() const;
    void addObjects(Type type, unsigned int amount);
    void addStuff(Object* obj);
    void eraseObject(Object* obj);
    int GO();
    Cell* findEmptyCell(Coords crd);
    Cell* findPrey(Coords crd);
};
#endif //OCEAN_H
