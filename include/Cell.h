#pragma once

#include "Object.h"

struct Couple {
	int x;
	int y;
};

class Ocean;

class Cell {
private:
	Couple couple;
	Object* object;
public:
	Cell(Couple c = {0, 0}, Object* obj = nullptr);
	Couple getCouple();
	Object* getObject();
	Object* createObj(ObjType type);
	void setObject(Object* obj);
	void init(Couple c, Object* obj);
	ObjType getObjectType();
};
