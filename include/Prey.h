#pragma once
#include "Object.h"

class Prey : public Object {
protected:
	int lifeTime;
	int breedTime;
	
public:
	Prey();
	void move();
	void breed();
	void die();
	void live() override;
};