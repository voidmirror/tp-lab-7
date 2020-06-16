#pragma once

#include "Ocean.h"

class Cell
{
private:
	Pair crd;
	Object* obj;
	Ocean *ocean;

public:
	explicit Cell(Pair p = { 0, 0 }, Ocean* oc = nullptr) :	crd(p),	obj(nullptr), ocean(oc) {}
	void init(Pair p, Ocean* oc);
	Object* get_object() const;
	void set_object(Object* obj_, bool flag_, ObjType type_);	//	flag_ - new obj_, or not
	void kill_me();
	void no_chance();
	Cell* try_find_cell_with_prey();
	Cell* try_find_empty_cell(bool flag_);
};
