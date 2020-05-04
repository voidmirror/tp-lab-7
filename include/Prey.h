#pragma once
#include "Object.h"

class Prey : public Object {
protected: 
	int lifetime;
	int breedingtime;
	unsigned int pulse = 0;
	unsigned int breed_pulse = 0;
public:
	Prey();
	bool moveOneStep(Directions direction, Object* obj); // returns 1, if moves, returns 0 if is not able to 
	void move();
	void breed();
	void live() override;
};