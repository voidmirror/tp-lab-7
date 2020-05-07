#pragma once
#include "Cell.h"

class Object {
protected:
	Cell* cell;
public:
	Object(Cell* cell);
	virtual ~Object() = 0;
	void setCell(Cell* cell);
	Cell* getCell() const;
	void moveToCell(Cell* cell);
	// This method is made virtual instead of static so that it can be overridden in derived classes.
	// In the case of static const symbol would be overshadowed but not overridden, so getting it by Object* pointer 
	// inside a Cell object would result in getting a char from the Object class ('?'), not from a derived one.
	virtual char getSymbol() const;
};
