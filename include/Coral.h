#pragma once

#include "Stone.h"

class Coral : public Stone
{
public:
	Coral(Cell* cell_);
	~Coral() = default;
	bool live() override;
	void spawn() override;
};
