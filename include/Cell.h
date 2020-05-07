#pragma once

#include "Common.h"
#include "Ocean.h"

class Object;
class Cell {
private:
	pair crd;
	Object* obj;
	Ocean* ocean;
public:
	Cell();
	void init(pair crd, Ocean* ocean);
	void setObj(Object* obj);
	void setCrd(pair crd);
	void killMe();
	pair getCrd();
	Object* getObj();
	Ocean* getOcean();
};