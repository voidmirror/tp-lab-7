#include "Ocean.h"
#include <ctime>
#include <Windows.h>

int main() {
	srand(time(NULL));
	Ocean ocean;
	ocean.addObjects(ObjType::STONE, 300);
	ocean.addObjects(ObjType::PREY, 4000);
	ocean.addObjects(ObjType::PREDATOR, 100);
	ocean.addObjects(ObjType::PREDATOR, 300);
	int c = 0;
	while (ocean.count_predator != 0 && ocean.count_prey != 0) {
		//ocean.print();
		c++;
		ocean.run();
		//Sleep(2000);
		
		ocean.print();
		
	}
	ocean.print();
	std::cout << "\n\n\n" << "Days: " << c << "\nPredators: " << ocean.count_predator << "\nPreys: " << ocean.count_prey << "\nStones: " << ocean.count_stone << std::endl;
	
	return 0;
}