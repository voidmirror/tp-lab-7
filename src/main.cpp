
#include "Ocean.h"
#include <iostream>

using namespace std;

int main()
{
	Ocean  ocean;
	ocean.addObjects(50, ObjectType::PREY);
	ocean.addObjects(50, ObjectType::PREDATOR);
	ocean.addObjects(30, ObjectType::STONE);
	ocean.print();
	system("pause");
	for (int i = 0; i < 90; i++)
	{
		ocean.run();
		cout << "\n\n" << endl;
		ocean.print();
	}
}