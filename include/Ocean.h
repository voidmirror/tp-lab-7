#pragma once

#include "Cell.h"
#include <vector>

class Ocean {
private:
	Cell** cells;
	vector<Object*> stuff;
public:
	Ocean();
	~Ocean();
	void print() const;
	void add_objects(ObjectType, int);
	void run();
	void delete_object(Object*);
	Cell* free_cell(Pair);
	Cell* prey_cell(Pair);
};
