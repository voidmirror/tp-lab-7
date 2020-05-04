#pragma once

#include <iostream>
#include <list>
#include<random>

#include "Objects.h"


#define TIME_TO_LIVE_PREY 6
#define TIME_TO_LIVE_PREDATOR 7
#define TIME_TO_BORN_PREY 4
#define TIME_TO_BORN_PREDATOR 5

using namespace std;

struct Cordinate
{
	int i;
	int j;
};

class Cell;
class Object;

class Ocean
{
public:
	Ocean(int n, int m);
	~Ocean();
	void init(int preys, int predators, int stones);
	void startSimulation(); 
	void startSimulation(int nIter);
	void print() const;
	void addObject(Object* object, Cordinate cord);
	Cell* getCell(Cordinate cord);
	void addToList(Object* obj);
	void deleteFromList(Object* obj);
	
private:
	int n;
	int m;
	Cell** matrix;
	list<Object*> objects;
	list<Object*> objToDelete;
	int amount;
	int preysAmount;
	int predatorsAmount;
	int iteration;
	bool checkCord(Cordinate cord);
	Cell* findRandEmpty();
	void nextIteration();
};




class Cell
{
public:
	Cell(Ocean* ocean, Cordinate cord);
	~Cell();
	void killObject();
	void addObject(Object* object);
	bool isEmpty();
	friend bool Empty(Cell* Cell);
	//bool Empty(Cell* Cell);
	friend bool WherePrey(Cell* cell);
	friend bool NotPredator(Cell* cell);
	Cell* findNear(bool condition(Cell*));
	void fishSwimAway();
	char objIcon();
private:
	Ocean* ocean;
	Object* object;
	Cordinate cord;
};

