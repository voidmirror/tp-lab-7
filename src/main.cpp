#include <iostream>
#include "Ocean.h"
#include <cstdlib>
#include "Prey.h"

int main() {
    Ocean ocean = Ocean(25,10);
	ocean.createObjects();
	ocean.mainloop();
}
