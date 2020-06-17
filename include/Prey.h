#pragma once
#include "Object.h"

class Prey : public Object {
protected: 
	int lifetime;
	int breeding;
	unsigned int tick = 0;
	unsigned int breed = 0;
public:
	Prey();
	bool moveOneStep(Directions direction, Object* obj);
	void move();
	void breed();
	void exist() override;
};