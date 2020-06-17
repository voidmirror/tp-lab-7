#include <iostream>
#include "include/Ocean.h"


int main()
{
    Ocean ocean;
    ocean.addObjects(ObjType::STONE, 50);
    ocean.addObjects(ObjType::PREY, 50);
    ocean.addObjects(ObjType::PREDATOR, 5);
    ocean.print(cout);
    size_t day = 0;
    while (ocean.preys >0 && ocean.predators >0)
    {
        day++;
        cout << "day:" << day  << " preys:" << ocean.preys << " predators:" << ocean.predators << endl;
        ocean.run();
        ocean.print(cout);
    }
    return 0;
}
