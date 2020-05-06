#pragma once
#include "ocean.h"
#include "object.h"

class Stone : public Object
{
public:
	Stone(Cell*);
	void live();
};