#pragma once

#include "Common.h"

class Object;
class Cell;

class Ocean
{
private:
	Cell **cells;
	list<Object*> stuff;

public:
	friend class Cell;

	Ocean();
	~Ocean();
	void print() const;
	void add_objects(ObjType type_, unsigned int count_);
	void delete_object(Object *obj_);
	void add_stuff(Object* obj_); 
	void run();
	Cell* try_find_prey(Pair crd_) const;
	Cell* try_find_empty_cell(Pair crd_) const;
	Cell* find_cell(Pair crd);
	int not_find_their_place = 0;
	int count_pred = 0;
	int count_prey = 0;
	int count_coral = 0;
	int count_stone = 0;
	int suicide = 0;
};
