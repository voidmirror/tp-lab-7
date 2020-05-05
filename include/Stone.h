#pragma once

#include "Object.h"

class Stone : public Object {
public:
	Stone(Cell* cell);
	~Stone() = default;
	bool live() override { return true; };
};