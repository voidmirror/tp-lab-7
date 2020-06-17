#include "ocean.h"

int main()
{
	Ocean* ocean = new Ocean();
	ocean->addObjects(50, ObjType::PREY);
	ocean->addObjects(50, ObjType::PREDATOR);
	ocean->addObjects(50, ObjType::CORAL);
	ocean->addObjects(50, ObjType::STONE);
	ocean->print();
	while(1) {
		ocean->run();
	}
}