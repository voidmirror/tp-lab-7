#include "Ocean.h"
#include <Windows.h>
#include <fstream>
#include <conio.h>

#define height 35
#define width 165

int main() {
	//ofstream fl1, fl2;
	//fl1.open("prey.txt");
	//fl2.open("predator.txt");
	Couple c;

	Ocean ocean(height, width);
	ocean.addObjects();
	ocean.print();
	ocean.printNumbers();
	system("pause");

	int i = 0;
	while(1) {
		ocean.print();
		ocean.printNumbers();
		c = ocean.getNumbers(); ////
		//fl1 << c.x << '\t'; ////
		//fl2 << c.y << '\t'; ////
		cout << "Press Enter to stop   " << "Step: " << i;
		if (c.x == 0 || c.y == 0) break;
		if (_kbhit())
			if (_getch() == '\r') break;
		i++;
		ocean.step();
	}
	ocean.print();
	ocean.printNumbers();

	system("pause");
	return 0;
}