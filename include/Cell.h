#pragma once
#include "Common.h"
#include "Ocean.h"

using namespace std;

class Object;
class Ocean;
class Cell
{
	friend Ocean;
	friend Object;
private:
	Pair crd;
	Object* obj = nullptr;
	Ocean* ocean;
public:

	Cell();
    void init(Pair p, Ocean* oc);
	Object* getObject();
	void setObject(Object* NewObj);
	void killMe();
};