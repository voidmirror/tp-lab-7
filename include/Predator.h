#pragma once
#include "Object.h"
#include "Prey.h"

class Predator : public Prey {
private:	
	int stomach = 80;
public:
	Predator();
	void breed();
	void kill();
	void exist() override;
}; 