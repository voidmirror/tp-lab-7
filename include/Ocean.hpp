#ifndef Ocean_hpp
#define Ocean_hpp

#include <stdio.h>
#include <list>
#include "Defaults.h"
#include "Cell.hpp"
#include "Stone.hpp"
#include "Object.hpp"
#include "Prey.hpp"
#include "Predator.hpp"

using namespace std;

class Object;
class Cell;

class Ocean
{
    friend Cell;

private:
    Cell **cells;
    list<Object*> creatures;
    int size_pred = 0;
    int size_prey = 0;

public:
    Ocean();
    ~Ocean();
    
    int* print() const;
    void addObj(ObjType type, unsigned int value);
    void killObj(Object *obj);
    void produceObj(Object *obj);
    void run();
    
    Cell* findPrey(Coord crd) const;
    Cell* findCell(Coord crd);
};

#endif /* Ocean_hpp */
