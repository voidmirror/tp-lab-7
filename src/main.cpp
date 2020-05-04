#include <iostream>
#include <time.h>
#include <dos.h>
#include <windows.h>
#include "Common.h"
#include "Ocean.h"
#include "Cell.h"
#include "Object.h"

using namespace std;

int main() {
	Ocean oc1;
	oc1.addAll(50, 20, 5);
	//oc1.print();
	oc1.run();	
	return 0;
}