#include "Ocean.h"
#include <ctime>
#include <time.h>
#include <cstdlib>

int main() {
	srand(time(0));
	Ocean* ocean = new Ocean;
	ocean->add_objects(ObjectType::STONE, 10);
	ocean->add_objects(ObjectType::PREY, 40);
	ocean->add_objects(ObjectType::PREDATOR, 30);
	ocean->print();
	ocean->run();
	delete ocean;
}