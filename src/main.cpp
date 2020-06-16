#include <iostream>

#include "Ocean.h"

using namespace std;

int main(){
	Ocean* ocean = new Ocean;
	ocean->AddObjects(50, ObjectType::PREY);
	ocean->AddObjects(25, ObjectType::PREDATOR);
	ocean->AddObjects(10, ObjectType::STONE);
	ocean->Run();

	system("pause");
	return 0;
}