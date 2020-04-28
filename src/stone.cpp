#include "stone.h"

int	Stone::count = 0;

Stone::Stone(Cell* cell) : Object(cell) {
	count++;
	live_time = rand() % 99999999 + 1;
}
void Stone::live() {
	if (--live_time <= 0) {
		count--;
		cell->clearCell();
		setCell(nullptr);
	}
}

char Stone::getName() {
	return name;
}

int Stone::getCount() {
	return count;
}