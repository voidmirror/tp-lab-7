//
// Created by Илья on 001 01.05.20.
//

#include <iostream>
#include <ctime>
#include "ocean.h"
using std::cout;
using std::endl;

int main(){
    srand(unsigned(time(0)));
    Ocean* ocean = new Ocean();
    ocean->addObjects(ObjType::STONE, 200);
    ocean->addObjects(ObjType::PREDATOR, 80);
    ocean->addObjects(ObjType::PREY, 30);
    ocean->print();
    ocean->run();
    ocean->print();
}

