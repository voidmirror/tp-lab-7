#pragma once
#include "Object.h"


class Cell {

    Object* object;
	coord location;
    static const char symbol = 250;
	
public:
	Cell();
	Cell(coord location);
	void setObject(Object* object);
	Object* getObject();
    bool isEmpty();
    void printSymbol();
	char getSymbol();
	coord* getLocation();
	void setLocation(coord location);
};