//
// Created by Anton Korkunov on 02/04/2020.
//
#include "Cell.h"

void Cell::init(Pair p, Ocean* oc){
    crd = p;
    ocean=oc;
}

Object* Cell::getObject() const{
    return obj;
};

void Cell::setObject(Object * tmp) {
    obj=tmp;
}

void Cell::killMe() {
    ocean->DeleteObj(obj);
   // obj->setCell(nullptr);
    delete obj;
    obj= nullptr;
}

Cell* Cell::CheckAround(){
  return ocean->FindEmpty(crd);
}
Cell* Cell::CheckAround_for_Prey(){
    return ocean->FindObject(crd, PREY_N);
};

void Cell::Call_to_add(){
    ocean->addObject(obj);
};