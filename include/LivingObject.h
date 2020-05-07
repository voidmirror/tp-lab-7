#pragma once
#include "Object.h"
#include <vector>
#include <list>

class LivingObject : public Object {
protected:
	int health;
public:
	LivingObject(Cell* cell);
	virtual std::vector<Cell*> possibleMoves(Cell** cellsArray, int height, int width) const = 0;
	//Returns the number of newly created Objects in ocean.
	virtual unsigned live(std::vector<Cell*> possibleMoves, std::list<LivingObject*>& listForNewObj) = 0;
	void setHealth(int health);
	int getHealth() const;
};
