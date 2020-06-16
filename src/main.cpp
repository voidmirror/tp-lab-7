#include "Context.h"
#include "Ocean.h"


int main()
{
	Ocean* ocean = new Ocean();
	ocean->AddObjects(ObjType::PREY, preyCounter);
	ocean->AddObjects(ObjType::STONE, objectsCounter / 2);
	ocean->AddObjects(ObjType::CORAL, objectsCounter / 2);
	ocean->AddObjects(ObjType::PREDATOR, predatorsCounter);
	ocean->Run(iters);
}