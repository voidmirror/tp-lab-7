#include "Ocean.h"
#include "Stone.h"
#include "Prey.h"
#include "Predator.h"
#include <iostream>

int main() {
	Ocean* oc = new Ocean(N, M);
	oc->addLivingObjects<Prey>(M * N / 10);
	oc->addLivingObjects<Predator>(M * N / 25);
	oc->addNonLivingObjects<Stone>(M + N * 2);
	oc->run();
	delete oc;
	return 0;
}