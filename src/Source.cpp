#include "Cell.h"
#include "Ocean.h"
#include "Object.h"
#include "Stone.h"
#include "Prey.h"
#include "Predator.h"
#include <Windows.h>


#include "Additional.h"

#include <iostream>
#include <ctime>
using namespace std;

int main() {
	srand(time(nullptr));
	Ocean ocean(25, 25, 50, 100, 100);
	ocean.run(51);
	return 0;
}