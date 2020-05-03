#include "Ocean.h"


int main()
{
	srand(time(NULL));
	system("mode con cols=150 lines=50");
	Ocean ocean;
	ocean.addObjects(ObjType::STONE, 100);
	ocean.addObjects(ObjType::PREY , 200);
	ocean.addObjects(ObjType::PREDATOR, 20);
	ocean.run();
}