//
//  Object.cpp
//  Ocean
//
//  Created by Олеся Мартынюк on 05.05.2020.
//  Copyright © 2020 Olesia Martinyuk. All rights reserved.
//

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

