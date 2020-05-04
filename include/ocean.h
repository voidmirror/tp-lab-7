//
// Created by sdanilov on 4/14/2020.
//

#ifndef LAB7_OCEAN_H
#define LAB7_OCEAN_H

#include <vector>
#include "Object.h"
#include "Cell.h"
#include "ObjectManufacture.h"
#include <string>
#include <map>

using namespace std;
class Cell;

class Ocean {
    vector<string> types = {"stone", "prey", "predator"};
public:
    void fillOcean(int size);
    vector<vector<Cell*>> matrix;
    void run();
    void print();
	bool check();
    int size;
    Cell* getRandomCellfromOcean();
};


#endif //LAB7_OCEAN_H
