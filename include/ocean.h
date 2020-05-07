#ifndef LAB7_OCEAN_H
#define LAB7_OCEAN_H

#include <vector>
#include "Object.h"
#include "Cell.h"
#include "Factory.h"
#include <string>
#include <map>

using namespace std;
class Cell;

class Ocean {
    vector<string> types = {"stone", "prey", "predator"};
public:
    void generateLifeOcean(int size);
    vector<vector<Cell*>> matrix;
    void run();
    void print();
	bool check();
    int size;
    Cell* chooseCell();
};


#endif
