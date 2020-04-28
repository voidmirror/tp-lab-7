#include "Context.h"
#include "Cell.h"

void Cell::Init(Pair pair, Ocean* ocean)
{
	this->coordinates = pair;
	this->ocean = ocean;
	object = nullptr;
}

void Cell::SetObject(Object* object)
{
	this->object = object;
}

void Cell::SelfDelete()
{
	object = nullptr;
}