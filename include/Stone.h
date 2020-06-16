#pragma once
#include "Object.h"
//#include <cstring>

class Stone :
	public Object
{

public:
	Stone(int x, int y, Ocean* ocean);
	Stone(coord Coordinates, Ocean* ocean);
	//void live();
	std::string getName();
};

