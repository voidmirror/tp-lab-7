#include <iostream>
#include "Ocean.h"
#include <cstdlib>
#include "Prey.h"

int main() {
    Ocean ocean = Ocean(35,30);
	ocean.createObjects();
    ocean.print();
	ocean.mainloop();
}