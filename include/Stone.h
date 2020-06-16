#pragma once
#include "Object.h"

class Stone :
	public Object
{

public:
	Stone(int x, int y, Ocean* ocean);
	Stone(coord Coordinates, Ocean* ocean);
	std::string getName();
};

