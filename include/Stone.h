#pragma once


#include "Object.h"
#include "Cell.h"
#include "Ocean.h"
#include "common.h"

class Stone : public Object
{

public:
	Stone(Cell* cell);
	bool live() override;

};

