#pragma once

#include "Common.h"

#define STONE_N '#'
#define PREY_N 'f'
#define PREDATOR_N 'S'

#define REPRODUCE_TIME_PREY 8
#define REPRODUCE_TIME_PREDATOR 10

#define MAX_DAYS_WITHOUT_FOOD 3

#define LIFESPAN_OF_PREY 15
#define LIFESPAN_OF_PREDATOR 20

enum class ObjType{STONE, PREY, PREDATOR};

class Cell;
class Object {
protected:
	Cell* cell;
	ObjType type;
	char symbol;
	int reproduce_time;
	int lifespan;
public:
	Object(Cell*  cell= nullptr);
	virtual ~Object() = default;
	virtual bool live() = 0;
	virtual void reproduce() {};
	virtual void move() {};
	void setCell(Cell*);
	Cell* getCell() const;
	ObjType getType() const;
	char getSymbol() const;
	virtual void EatenByPredator() {};
	void setLifespanForEat(int days) { lifespan = days; };
};