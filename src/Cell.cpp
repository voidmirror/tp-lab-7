#include "Object.h"

void Cell::init(Pair p, Ocean *oc) 
{
	ocean = oc;
	crd = p;
}

Object* Cell::get_object() const 
{
	return obj;
}

void Cell::set_object(Object* obj_, bool flag_, ObjType type_) 
{
	obj = obj_;
	if (flag_)
	{
		ocean->add_stuff(obj_);
		switch (type_)
		{
			case ObjType::PREDATOR:
				ocean->count_pred++;
				break;
			case ObjType::PREY:
				ocean->count_prey++;
				break;
			case ObjType::STONE:
				ocean->count_stone++;
				break;
			case ObjType::CORAL:
				ocean->count_coral++;
				break;
			default:
				break;
		}
	}
}

void Cell::kill_me() 
{
	if (obj) 
	{
		delete obj;
		obj = nullptr;
	}
}

Cell* Cell::try_find_empty_cell(bool flag_)
{
	if (!flag_ && obj->get_type() == ObjType::PREY)
	{
		return ocean->find_cell(crd);
	}
	else
	{
		return ocean->try_find_empty_cell(crd);
	}
}

Cell* Cell::try_find_cell_with_prey()
{
	return ocean->try_find_prey(crd);
}

void Cell::no_chance()
{
	ocean->not_find_their_place++;
}
