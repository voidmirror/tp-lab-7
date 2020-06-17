#include <iostream>
#include "Ocean.h"

int main() {
    srand(time(0));
    auto *ocean = new Ocean(100, 20, 0, 500, 50, 100);

    while (ocean->checkIfExistSomeone() && ocean->checkIfExistPredators()) {
        std::cout << "\n\n\n";
        ocean->timeTick();
        ocean->showMap();
    }

    return 0;
}
