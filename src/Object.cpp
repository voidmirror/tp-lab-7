//
// Created by iddoroshenko on 26.03.2020.
//

#include "Object.h"

Object::Object(ObjType _objType) : objType(_objType), _isDead(false), cell(nullptr) {}

void Object::setCell(Cell* _cell) {
    cell = _cell;
}

ObjType Object::getObjType() const {
    return objType;
}

Object::~Object() {
    cell = nullptr;
}

bool Object::isDead() const {
    return _isDead;
}

void Object::killObj() {
    _isDead = true;
}

