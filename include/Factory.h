#ifndef TASK1_Factory_H
#define TASK1_Factory_H
#include "Object.h"
#include "Cell.h"
#include <string>
using namespace std;
class Object;
class Cell;


class Factory {
public:
    static Object* newObject(const string& type, Cell* cell);
	static Object* newRandomObject(Cell* cell);
};


#endif