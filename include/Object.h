#pragma once
#include "common.h"
#include <vector>
#include <iostream>

enum class ObjType {  FREE, STONE, PREY, PREDATOR };
const char icons[] = {  FREE_CELL_N, STONE_N , PREY_N, PREDATOR_N };


class Cell;
class Object
{
protected:
	Cell *cell;
	ObjType type;
	int id;

public:
	Object(Cell *cell = nullptr) : cell(cell) {  }
	//virtual ~Object();
	int getId();
	virtual void live() = 0;
	void setCell(Cell*);
	void setId(int);
	void setType(ObjType);
	ObjType getType() const;
	static Object* createObject(ObjType type);
	void print() {
		if (this != nullptr) {
			std::cout << "OBJECT " << "ID " << id << " TYPE " << static_cast<int>(type) << std::endl;
		}
		else {
			std::cout << "OBJECT NULL" << std::endl;
		}
		
	}
};