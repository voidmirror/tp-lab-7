//
// Created by sdanilov on 4/14/2020.
//

#ifndef TASK1_OBJECTMANUFACTURE_H
#define TASK1_OBJECTMANUFACTURE_H
#include "Object.h"
#include "Cell.h"
#include <string>
using namespace std;
class Object;
class Cell;


class ObjectManufacture {
public:
    static Object* newObject(const string& type, Cell* cell);
	static Object* newRandomObject(Cell* cell);
};


#endif //TASK1_OBJECTMANUFACTURE_H
