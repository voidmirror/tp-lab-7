#include "Ocean.h"
#include <time.h>

int main() {
	srand(time(nullptr));
	Ocean* ocean = new Ocean;
	ocean->init();
	ocean->addObjects(stones, preys, predators);
	ocean->print();
	ocean->run(speed);
	delete ocean;
	return 0;
}