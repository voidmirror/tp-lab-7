#include "../include/Object.h"
#include "../include/Cell.h"

std::ostream &operator<<(std::ostream & out, const Object &obj)
{
    ObjType type = obj.getType();
    switch (type)
    {
        case ObjType::STONE:
        {
            return out << symbols[0];
        }
        case ObjType::PREY:
        {
            return out << symbols[1];
        }
        case ObjType::PREDATOR:
        {
           return out << symbols[2];
        }
    }
}

void Object::setCell(Cell * new_cell)
{
    cell = new_cell;
}

Cell *Object::getCell() const
{
    return cell;
}

ObjType Object::getType() const
{
    return type;
}

