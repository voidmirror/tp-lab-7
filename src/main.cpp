
#include "ocean.h"
#include <ctime>
#include <time.h>
#include <cstdlib>
using namespace std;

int main() {
	srand(time(nullptr));
	Ocean* ocean = new Ocean;
	ocean->init();
	ocean->addObjects(stones,preys,predators); 
	ocean->print();
	ocean->run(speed);
	delete ocean;
	return 0;
}