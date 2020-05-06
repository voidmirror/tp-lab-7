#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <dos.h>
#include <windows.h>
#include "Common.h"
#include "Ocean.h"
#include "Cell.h"
#include "Object.h"

using namespace std;

int main(){
	Ocean ocean;
	ocean.addManyObjects(ObjType::STONE, 5);
	ocean.addManyObjects(ObjType::PREY, 2);
	ocean.addManyObjects(ObjType::PREDATOR, 2);
	ocean.run();
	return 0;
}