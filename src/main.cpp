//
// Created by Mary on 15.04.2020.
//
#include "ocean.h"
int main()
{

    auto ocean = new Ocean(ocean_size.first, ocean_size.second);
    ocean->addCreatures(ObjType::PREDATOR, 2);
    ocean->addCreatures(ObjType::PREY, 10);

    ocean->addCreatures(ObjType::STONE, 15);
    ocean->live(130);
    return 0;
}
