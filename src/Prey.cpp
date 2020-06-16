#include "Prey.h"
#include "Cell.h"
#include "Ocean.h"
#include <ctime>
#include <cstdlib>


#define PREY 158

Prey::Prey(int x, int y, Ocean* ocean) : LivingObject(x, y, ocean) { symbol = PREY; }

Prey::Prey(coord coordinates, Ocean* ocean): LivingObject(coordinates, ocean) { symbol = PREY; }

void Prey::live()
{	
	motion();
	multiply();

	daysOfLife -= 1;
	if (daysOfLife == 0) {
		die();
	}
}

bool Prey::checkCell(Cell* cell) {
	return cell->isEmpty();
}

void Prey::eat(Cell* cell){}

void Prey::multiply() {
	if (daysBeforeBreeding == 0) {
		std::vector<Cell*> forBaby = getNeirboringCells();

		for(int i = forBaby.size()-1; i >= 0; i--){
			if (forBaby[i]->isEmpty() == false) {
				forBaby.erase(forBaby.begin() + i);
			}
		}
		if (forBaby.size() != 0) {
			int index = rand() % forBaby.size();
			Prey* littlePrey = new Prey(*forBaby[index]->getLocation(), ocean);
			littlePrey->birth();
		}
		daysBeforeBreeding = 5;
	}
	else {
		daysBeforeBreeding--;
	}
}

std::string Prey::getName() { return "Prey"; }