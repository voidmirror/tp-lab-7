//
// Created by aklen on 21.04.2020.
//
#include <iostream>
#include "Ocean.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    srand(time(nullptr));
    Ocean ocean({20,20});
    ocean.addObjects(ObjType::PREY, 40);
    ocean.addObjects(ObjType::PREDATOR, 15);
    ocean.addObjects(ObjType::STONE, 15);
    ocean.print();
    ocean.live(150);
    return 0;
}
