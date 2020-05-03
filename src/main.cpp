#include "ocean.h"

int main()
{
    Ocean ocean = Ocean();

    ocean.addStartObjects(ObjType::PREDATOR, 80);
    ocean.addStartObjects(ObjType::PREY, 100);
    ocean.addStartObjects(ObjType::STONE, 20);

    while (true)
    {
        ocean.run();
        int* results = ocean.print();
        if (results[0] == 0 || results[1] == 0)
        {
            break;
        }
    }
}
