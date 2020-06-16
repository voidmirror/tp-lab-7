#ifndef STONE_H
#define STONE_H

#include "Object.h"

class Stone :public Object {
public:
	Stone(Cell* cell) : Object(cell) {
		type = ObjType::STONE;
	}
	virtual int live()override {
		return 1;
	}
	virtual char getObjectType() override {
		return STONE_N;
	}
};

#endif // !STONE_H
