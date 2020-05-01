#pragma once //fix

#include "Common.h"
#include "Object.h"
#include "Ocean.h"

class Ocean;

class Cell{
	friend Ocean;
private:
	Pair cords;
	Object* obj;
	Ocean* ocean;
public:
	explicit Cell(Pair p = { 0, 0 }, Ocean* oc = nullptr) :
		cords(p),
		obj(nullptr),
		ocean(oc) {}
	void Init(Pair p, Ocean* oc);
	Object* GetObject();
	void SetObject(Object*newobj);
	void KillMe();
	Ocean* GetOcean();
	Cell* FindEmptyNeighbour();
	Cell* FindPreyNeighbour();
	Pair Cords();
	void Move();
};