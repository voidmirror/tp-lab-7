#include "Ocean.h"
#include <ctime>
#include <time.h>
#include <cstdlib>

int main() {
	srand(time(0));
	Ocean* ocean = new Ocean;
	ocean->addObjs(ObjType::PREY, 100);
	ocean->addObjs(ObjType::PREDATOR,50);
	ocean->addObjs(ObjType::STONE, 15);
	ocean->print();
	ocean->run();
	delete ocean;
}