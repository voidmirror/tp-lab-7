//
// Created by Оксана on 04.05.2020.
//

#include <object.h>
#include <cell.h>

Object::Object(Cell* c){
    type = ObjType::NONE;
    cell = c;
}

void Object::setCell(Cell * c){
    cell = c;
}

ObjType Object::getObjectType() const{
    return type;
}

Cell* Object::getCell() const{
    return cell;
}

char Object::getSymb(){
    return symb;
}

Object::~Object() {

}
