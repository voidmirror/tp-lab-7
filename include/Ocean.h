#pragma once
#include <list>
#include <vector>
#include <unordered_set>
#include <random>
#include <ostream>

#include "common.h"
#include "Cell.h"

using namespace std;


class Object;
class Cell;

class Ocean {
    friend class Cell;
private:
    vector<vector<Cell*>> cells;
    list<Object*> stuff;
    vector<Pair> empty_cells;

public:
    Ocean();
    ~Ocean();
    void run();

    void addObjects(ObjType type, size_t count);
    void deleteObject(Object* obj);
    void addStuff(Object *obj);

    Cell* findEmptyCell(Pair coord) const;
    Cell* findType(Pair coord, ObjType type) const;

    void print(ostream& out) const;

    size_t stones;
    size_t preys;
    size_t predators;
};