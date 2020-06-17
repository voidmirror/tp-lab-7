#include "Object.hpp"

Object::Object(Cell *c) : cell(c) {}


Cell* Object::getCell(){
    return this->cell;
}

ObjType Object::getType(){
    return this->type;
}


void Object::setLifetime(int lifetime){
    this->lifetime = lifetime;
}

