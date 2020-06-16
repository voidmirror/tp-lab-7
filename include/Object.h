#pragma once

#include "Cell.h"

class Cell;

class Object
{
protected:
	Cell* cell;
	int days_of_life;
	char symbol;
	ObjType type; 
	int spawn_time; 
	int try_to_spawn = 0;

public:
	Object(Cell * cell_ = nullptr);
	virtual ~Object() = default;
	Cell* get_cell() const;
	ObjType get_type() const; 
	void set_days_of_life(int days_of_life_);
	char get_symbol();
	virtual bool live() = 0;
	virtual void move() {};
	virtual void spawn() {};
	virtual void easy_prey() {};
};


