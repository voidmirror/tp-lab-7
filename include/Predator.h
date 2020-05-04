#pragma once
#include "LivingObject.h"

class Cell;

class Predator :
	public LivingObject
{
	int energy = 100;
public:
	Predator(int x, int y, Ocean* ocean);
	Predator(coord Coordinates, Ocean* ocean);
	void eat(Cell* cell);
	void multiply();
	std::string getName();
	Cell* findFood();
	bool isFood(Cell* cell);

	void live();
	bool checkCell(Cell* cell);
};

