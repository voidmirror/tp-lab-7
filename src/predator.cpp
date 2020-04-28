#include "predator.h"

int	Predator::count = 0;
int Predator::reproduce_time = rand() % 50 + 1;

Predator::Predator(Cell* cell) : Object(cell) {
	count++;
	live_time = rand() % 75 + 1;
}

void Predator::move() {
	Pair crd = cell->getCrd();
	Cell* victim = getCell()->getOcean()->hunting(crd);
	if (victim == nullptr) { // поблизости нет жертв
		victim = getCell()->getOcean()->getFreeCell(crd);
		getCell()->clearCell();
		victim->setObject(this);
		setCell(victim);
	}
	else {
		live_time += 2; 
		victim->getObject()->setLiveTime(-4);
		victim->getObject()->setCell(nullptr);
		getCell()->clearCell();
		victim->setObject(this);
		setCell(victim);
	}
}

void Predator::reproduce() {
	Pair crd = cell->getCrd();
	int children = rand() % 3; // Сколько родится?
	for (size_t i = 0; i < children; i++) {
		Cell* child = getCell()->getOcean()->getFreeCell(crd);
		if (cell != child) { // Функция нашла свободное место для child (ребёнок не погибает)
			Object* object = new Predator(child);
			child->setObject(object);
			this->reproduce_time = 100;
			this->getCell()->getOcean()->addChild(object);
		}
		else
			break; // Нет места для нового потомства
	}
}

void Predator::live() {
	if (--live_time <= 0) {
		count--;
		cell->clearCell();
		setCell(nullptr);
		if (count == 0) {
			system("cls");
			cout << "STOP... There is no predators" << endl;
			exit(1);
		}
	}
	else {
		move();
		if (--reproduce_time <= 0 && live_time >= 100) {
			reproduce_time = 75;
			reproduce();
		}
	}
}

char Predator::getName() {
	return name;
}

int Predator::getCount() {
	return count;
}