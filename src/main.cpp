#include "Ocean.h"

int main()
{
    Ocean oc(15, 40);
    oc.spawnObjects();
    oc.print();
    oc.run();
    return 0;
}