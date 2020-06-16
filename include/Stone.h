#pragma once

#include "Object.h"

class Stone : public Object
{
public:
	Stone(Cell* cell_);
	~Stone() = default;
	bool live() override;
};
