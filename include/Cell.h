#ifndef TASK1_CELL_H
#define TASK1_CELL_H
#include "Object.h"
#include "ocean.h"
#include <vector>
#include <string>
using namespace std;
class Ocean;
class Object;

class Cell {
public:
	Cell(Ocean* ocean);
	Ocean* ocean;
    Object* object;
    string type;
    void live();
    void die();
};


#endif

