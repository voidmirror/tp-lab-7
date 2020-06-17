#pragma once
#include "Object.h"
#include "Prey.h"

class Predator : public Prey {
private:
	int fullness;
public:
	Predator();
	void hunt();
	void live() override;
};