#include "Stone.h"
#include "Ocean_Enums.h"
Stone::Stone(Cell* cell) : Object(cell)
{
	this->type = Object_type::stone;
}

std::string Stone::draw()
{
	return "O";
}

Action Stone::live(Object_type up, Object_type down, Object_type left, Object_type right)
{
	return Action::nothing;
}