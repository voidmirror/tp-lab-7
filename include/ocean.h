//
// Created by Mikhail on 01.05.2020.
//

#ifndef TASK1_OCEAN_H
#define TASK1_OCEAN_H

#include <iostream>
#include <vector>
#include <set>
#include <helpers.h>
#include <cell.h>
#include <object.h>

using std::vector;
using std::set;
using std::pair;

class Ocean {
private:

    int n, m;
    vector<vector<Cell*> > cells;
    set<Object*> stuff;
    vector<vector<bool> > used;
    friend class Cell;
public:
    Ocean(int, int);
    void addObjects(ObjType, int);
    void addObject(Object*);
    void live(int iterations);
    void print();
    int getN();
    int getM();
    Cell* getCell(int, int);
    void swap(pair<int,int>, pair<int,int>);
    void fill(pair<int,int>);
    bool notUsed(pair<int,int>);
    void deleteObj(Cell*);

};
#endif //TASK1_OCEAN_H
