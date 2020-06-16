#include "Object.h"


//Object
Object::Object(Cell * cell)
{
	SetCell(cell);
}

void Object::SetCell(Cell* cell)
{
	this->cell = cell;
}
//Stone

ObjType Stone::GetType() const
{
	return type;
}

//Coral
ObjType Coral::GetType() const
{
	return type;
}