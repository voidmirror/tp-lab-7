//
// Created by Оксана on 19.04.2020.
//
#include "Ocean.h"

int main()
{
    Ocean* ocean = new Ocean();
    ocean->addObjects(ObjType::PREDATOR, 20);
    ocean->addObjects(ObjType::PREY, 100);
    ocean->addObjects(ObjType::STONE, 50);
    ocean->run(20);

}

