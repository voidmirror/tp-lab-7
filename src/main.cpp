//
// Created by Mikhail on 01.05.2020.
//
#include <iostream>
#include <ocean.h>

using std::cout;
using std::cin;

int main() {
    Ocean ocean(20, 200);
    ocean.addObjects(ObjType::STONE, 500);
    ocean.addObjects(ObjType::PREY,3000);
    ocean.addObjects(ObjType::PREDATOR, 1000);
    ocean.live(10000);
    return 0;
}