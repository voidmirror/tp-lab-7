#pragma once
#include "Object.h"

class Stone : public Object {
public:
	Stone(Cell* cell) : Object(cell) {}
	~Stone() override = default;
	virtual char getSymbol() const override;
};
