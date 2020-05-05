//
// Created by Оксана on 19.04.2020.
//
#include "stone.h"

Stone::Stone(Cell* c) :Object(c){
    type = ObjType::STONE;
    symb = STONE_N;
}

void Stone::live(){
}
void Stone::die(){

}