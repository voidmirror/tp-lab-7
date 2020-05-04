#include "Objects.h";
#include "Ocean.h";


int main() {
	cout << "START" << endl;
	Ocean* ocean = new Ocean(30, 30);
	ocean->init(100, 100, 100);
	
	ocean->print();
	ocean->startSimulation(10);
	//ocean->startSimulation();
}