#pragma once
#include "Object.h"

class Stone : public Object
{
public:
	Stone(Cell*, ObjType);
	bool live();
	char getChar();
};

