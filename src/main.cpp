#include <iostream>
#include "Ocean.cpp"

int main(int argc, const char * argv[]) {
    Ocean ocean = Ocean();

    ocean.addObj(ObjType::PREDATOR, 30);
    ocean.addObj(ObjType::PREY, 100);
    ocean.addObj(ObjType::STONE, 1);

    while (true)
    {
        ocean.run();
        int *res = ocean.print();
        if (res[0] == 0 || res[1] == 0)
        {
            break;
        }
    }

}
