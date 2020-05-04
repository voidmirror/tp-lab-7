#pragma once
#include "Common.h"
#include "Ocean.h"

class Object;
class Cell {
	friend Ocean;
private:
	Pair crd;
	Object* obj;
	Ocean* ocean;
public:
	Cell();
	Pair getCrd();
	Object* getObj();
	Ocean* getOcean();
	void init(Pair crd, Ocean* ocean);
	void setObj(Object* obj);
	void setCrd(Pair crd);
	void killMe();
};
