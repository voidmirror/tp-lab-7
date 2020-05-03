#pragma once

#include "Object.h"

class Ocean;

class Cell {
	friend Ocean;
private:
	Pair coord;
	Object* obj;
	Ocean* ocean;
public:
	explicit Cell(Pair p = {0, 0}, Ocean* oc = nullptr) :
		coord(p),
		obj(nullptr),
		ocean(oc) {}
	void init(Pair, Ocean*);
	Object* get_object();
	Ocean* get_ocean();
	Pair get_coord(); 
	void set_object(Object*);
	void clear_cell();
};
