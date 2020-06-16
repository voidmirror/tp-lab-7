#include "Cell.h"
#include "Object.h"
Cell::Cell(Ocean* ocean)
{
    this->ocean = ocean;
}

void Cell::setObject(Object* object){
    this->object = object;
    if(object != nullptr){
        this->objType = object->getObjType();
        this->object->setCol(this->column);
        this->object->setRow(this->row);
        this->object->setPlace(this);
    }else{
        this->objType = -1;
    }
}
