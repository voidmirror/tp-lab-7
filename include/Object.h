#pragma once

#include "Common.h"

enum class ObjectType { STONE, PREY, PREDATOR };
class Cell;

class Object {
protected:
	Cell* cell;
	ObjectType type;
public:
	Object(Cell* = nullptr);
	~Object() {};
	void set_cell(Cell*);
	Cell* get_cell();
	ObjectType get_type();
	virtual void live() = 0;
};
