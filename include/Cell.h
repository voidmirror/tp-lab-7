//
//  Cell.h
//  lab7
//
//  Created by Андрей Журавлев on 16.04.2020.
//  Copyright © 2020 Андрей Журавлев. All rights reserved.
//

#ifndef Cell_h
#define Cell_h
#include "Object.h"
#include "Coordinates.h"
#include "Ocean.h"
#include <random>



class Object;
class Ocean;

class Cell {
	Object* obj = nullptr;
	Point coord;
	Ocean* ocean;
public:
	Cell(Point coord = {0, 0}, Ocean* ocean = nullptr) : coord(coord), ocean(ocean) {}
	
	Object* getObject() { return this->obj; }
	void setObject(Object* obj);
	Point getCoord() { return coord; }
	void killObject() { obj = nullptr; }
	Cell* findEmptyCell();
	Cell* findPrey();
};




#endif /* Cell_h */
