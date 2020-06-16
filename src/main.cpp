//
// Created by Илья Соловьёв on 05.05.2020.
//

#include "ocean.h"
int main()
{
    srand(time(0));
    auto ocean = new Ocean(ocean_size.first, ocean_size.second);
    ocean->addCreatures(ObjType::PREDATOR, 6);
    ocean->addCreatures(ObjType::PREY, 30);

    ocean->addCreatures(ObjType::STONE, 45);
    ocean->live(130);
    return 0;
}