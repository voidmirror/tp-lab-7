#include "Ocean.h"
#include "Prey.h"

int main() {
    Ocean ocean = Ocean(50,8);
    ocean.createObjects();
    ocean.mainloop();
}