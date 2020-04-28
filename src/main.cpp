#include "common.h"
#include "ocean.h"
#include <ctime>
#include <time.h>
#include <cstdlib>
using namespace std;

int main() {
	srand(time(nullptr));
	Ocean* atlantic = new Ocean;
	atlantic->addObjects(10); 
	atlantic->print();
	atlantic->run(10);

	delete atlantic;
	return 0;
}