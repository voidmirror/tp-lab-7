#include "ocean.h"

int main() {

    auto ocean = new Ocean(ocean_size_x, ocean_size_y);
    ocean->addObjects(ObjType::PREDATOR, 5);
    ocean->addObjects(ObjType::PREY, 20);
    ocean->addObjects(ObjType::STONE, 10);
    ocean->live(500);
    return 0;
}
