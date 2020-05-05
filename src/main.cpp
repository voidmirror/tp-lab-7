#include <iostream>
#include "Ocean.cpp"

int main(int argc, const char * argv[]) {
    Ocean ocean = Ocean();

    ocean.addObj(ObjType::PREDATOR, 80);
    ocean.addObj(ObjType::PREY, 100);
    ocean.addObj(ObjType::STONE, 20);

    while (true)
    {
        ocean.run();
        ocean.print();
        if (res[0] == 0 || res[1] == 0)
        {
            break;
        }
    }

}
