#include "prey.h"

int	Prey::count = 0;
int Prey::reproduce_time = rand() % 50 + 1;

Prey::Prey(Cell* cell) : Object(cell) {
	count++;
	live_time = rand() % 100 + 1;
}

void Prey::move() {
	Pair crd = cell->getCrd();
	Cell* step = getCell()->getOcean()->getFreeCell(crd);
	getCell()->clearCell();
	step->setObject(this);
	setCell(step);
}

void Prey::reproduce() {
	Pair crd = cell->getCrd();
	int children = rand() % 7; // Сколько родится?
	for (size_t i = 0; i < children; i++) {
		Cell* child = getCell()->getOcean()->getFreeCell(crd);
		if (cell != child) { // Функция нашла свободное место для child (ребёнок не погибает)
			Object* object = new Prey(child);
			child->setObject(object);
			this->reproduce_time = 20;
			this->getCell()->getOcean()->addChild(object);
		}
		else
			break; // Нет места для нового потомства
	}
}

void Prey::live() {
	if (--live_time <= 0) {
		count--;
		if (live_time != -5) {
			cell->clearCell(); // освобождаем ячейку от объекта
			setCell(nullptr);
		}
		if (count == 0) {
			system("cls");
			cout << "STOP... There is no preys" << endl;
			exit(1);
		}
	}
	else {
		move();
		if (--reproduce_time <= 0) {
			reproduce_time = 10;
			reproduce();
		}
	}
}

char Prey::getName() {
	return name;
}

void Prey::death_counter() {
	count--;
}