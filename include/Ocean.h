//
// Created by Anton Korkunov on 02/04/2020.
//

#ifndef LAB7_OCEAN_H
#define LAB7_OCEAN_H
#include "common.h"
#include <vector>
#include <list>

class Cell;
class Object;

class Ocean{
private:
    int size;
    Cell **cells;
    std::vector<Object*> Vstuff;
   // std::list<Object*> stuff;
public:
    Ocean();
    ~Ocean();
    void print() const;
    void addObject(Object*);
    void addObjects();
    Cell* FindEmpty(Pair crd);
    void DeleteObj(Object*);
    void run();
    Cell* FindObject(Pair crd, std::string par);
};
#endif //LAB7_OCEAN_H
