#include "Object.h"

Object::Object(Cell *cell_) : cell(cell_) 
{

}

Cell* Object::get_cell() const 
{
	return cell;
}

ObjType Object::get_type() const 
{
	return type;
}

void Object::set_days_of_life(int days_of_life_)
{
	days_of_life = days_of_life_;
}

char Object::get_symbol()
{
	return symbol;
}
