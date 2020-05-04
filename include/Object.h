#ifndef OBJECT_H
#define OBJECT_H

#include "Additional.h"

class Cell; 

class Object {
public:
	Object();
	Object(Cell* cell);
	virtual void live() = 0;
	void setCell(Cell* cell);
	bool isDead() const;
	void kill();
	ObjectType getType() const;
	virtual ~Object() = default;
protected:
	Cell* cell;
	ObjectType type;
	bool alive;
};

#endif