#include "ocean.h"
#include <iostream>
#include <time.h>
using namespace std;

int main(){
	srand(time(NULL));
	Ocean ocean;
    ocean.generateLifeOcean(71);
	ocean.run();
}
