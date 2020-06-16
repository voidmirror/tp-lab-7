#pragma once
#include "Object.h"
#include "Ocean_Enums.h"
#include <string>

class Stone : public Object
{
public:
	Stone(Cell* cell);
	std::string draw() override;
	Action live(Object_type up, Object_type down, Object_type left, Object_type right) override;
};

