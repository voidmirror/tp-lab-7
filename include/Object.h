#pragma once
#include <string>
#include "Cell.h"
#include "Ocean_Enums.h"

class Object
{
protected:
	Object_type type;
	Cell* cell;
	Object(Cell* cell);
public:
	void set_cell(Cell* cell);
	Cell* get_cell();
	Object_type get_type();
	virtual Action live(Object_type up, Object_type down, Object_type left, Object_type right) = 0;
	virtual std::string draw() = 0;
};

