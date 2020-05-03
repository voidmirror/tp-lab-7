#include "Ocean.h"

int main()
{
	Ocean* ocean = new Ocean();
	ocean->addObjects(ObjType::PREDATOR, 10);
	ocean->addObjects(ObjType::PREY, 6);
	ocean->addObjects(ObjType::STONE, 20);
	ocean->run();
}
