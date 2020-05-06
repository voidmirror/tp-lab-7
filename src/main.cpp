#include <iostream>
#include "Common.h"
#include "Object.h"
#include "Cell.h"
#include "Ocean.h"

int main()
{
	Ocean  ocean;
	ocean.addObjects(50, ObjType::PREY);
	ocean.addObjects(35, ObjType::PREDATOR);
	ocean.addObjects(30, ObjType::STONE);
	ocean.print();
	system("pause");
	for (int i = 0; i < 500; i++)
	{
		ocean.move();
		ocean.eat();
		ocean.die();
		ocean.reproduce();
		ocean.print();
		system("pause");
		
	}
}