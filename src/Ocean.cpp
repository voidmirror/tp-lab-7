#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <time.h>

#include "Cell.h"
#include "Ocean.h"
#include "Object.h"
#include "Stone.h"
#include "Prey.h"
#include "Predator.h"

#include "Additional.h"

#ifdef __linux__ 

#include <unistd.h>
void wait() {
	sleep(1);
}
#else
#include "Windows.h"
void wait() {
	Sleep(1000);
}

#endif

Ocean::Ocean(int n, int m, int stones, int preys, int preds) {
	size = { n,m };
	cells.resize(n);
	for (int i = 0; i < n; i++) {
		cells[i].resize(m);
		for (int j = 0; j < m; j++) {
			cells[i][j] = new Cell(i, j, this);
		}
	}
	countPrey = 0;
	countPred = 0;
	genesis(stones, preys, preds);
}

Ocean::~Ocean() {
	for (int i = 0; i < size.first; i++) {
		for (int j = 0; j < size.first; j++) {
			delete cells[i][j];
		}
	}

	auto it = objects.begin();
	while (it != objects.end()) {
		delete* it;
		it = objects.erase(it);
	}
}


void Ocean::print() const {
	for (int i = 0; i < size.first; i++) {
		for (int j = 0; j < size.second; j++) {
			if (cells[i][j]->getObject() == nullptr) {
				std::cout << " ";
			}
			else {
				if (cells[i][j]->getObject()->getType() == ObjectType::STONE) {
					std::cout << ".";
				}
				else if (cells[i][j]->getObject()->getType() == ObjectType::PREY) {
					std::cout << "o";
				}
				else if (cells[i][j]->getObject()->getType() == ObjectType::PREDATOR) {
					std::cout << "O";
				}
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	wait();
}
void Ocean::addObject(std::pair<int, int> crd, ObjectType type) {
	Object* newObj;
	if (type == ObjectType::STONE) {
		newObj = new Stone(cells[crd.first][crd.second]);
	}
	else if (type == ObjectType::PREY) {
		newObj = new Prey(cells[crd.first][crd.second]);
		countPrey++;
	}
	else if (type == ObjectType::PREDATOR) {
		newObj = new Predator(cells[crd.first][crd.second]);
		countPred++;
	}
	objects.push_back(newObj);
	cells[crd.first][crd.second]->setObject(newObj);
}

std::pair<int, int> Ocean::getFreeCell() {
	int x, y;
	do {
		x = rand() % size.first;
		y = rand() % size.second;
	} while (cells[x][y]->getObject() != nullptr);
	
	return { x, y };
	
}
void Ocean::addObjects(int num, ObjectType type) {
	for (int i = 0; i < num; i++) {
		std::pair<int, int> crd = getFreeCell();
		addObject(crd, type);
	}
}


void Ocean::genesis(int stones, int preys, int preds) {
	std::vector<ObjectType> objs;
	for (int i = 0; i < stones; i++) {
		objs.push_back(ObjectType::STONE);
	}

	for (int i = 0; i < preys; i++) {
		objs.push_back(ObjectType::PREY);
	}

	for (int i = 0; i < preds; i++) {
		objs.push_back(ObjectType::PREDATOR);
	}

	std::random_device random_device;
	std::mt19937 generator(random_device());
	std::shuffle(objs.begin(), objs.end(), generator);

	for (int i = 0; i < objs.size(); i++) {
		std::pair<int, int> crd = getFreeCell();
		if (crd.first == 1'000'000) {
			std::cout << "Too much objects!\n";
			break;
		}
		addObject(crd, objs[i]);
	}
}


void Ocean::run(int epochs) {
	std::cout << "Initial state: \n";
	print();
	std::cout << "Start running!\n";
	for (int epoch = 0; epoch < epochs; epoch++) {

		auto it = objects.begin();
		while (it != objects.end()) {
			if ((*it)->isDead()) {
				delete *it;
				it = objects.erase(it);
			} else {				
				(*it)->live();
				++it;
			}
		}
		print();
		if (countPred == 0) {
			std::cout << "All predators have died. Game have ended on " << epoch + 1 << " epoch\n";
			return;
		}
		if (countPrey == 0) {
			std::cout << "All preys have died. Game have ended on " << epoch + 1 << " epoch\n";
			return;
		}
	}
	std::cout << "Game have successfully ended after " << epochs + 1 << " epochs\n";
}
void Ocean::decPrey() {
	countPrey--;
}

void Ocean::decPred() {
	countPred--;
}

void Ocean::incPrey()
{
	countPrey++;
}
void Ocean::incPred()
{
	countPred++;
}

std::pair<int, int> Ocean::getSize() const {
	return size;
}

bool Ocean::isEmpty(std::pair<int, int> crd) const {
	return cells[crd.first][crd.second]->getObject() == nullptr;
}

Cell* Ocean::getCell(std::pair<int, int> crd) const {
	return cells[crd.first][crd.second];
}

void Ocean::moveObject(Object* obj, std::pair<int, int> from, std::pair<int, int> to) {
	cells[to.first][to.second]->setObject(obj);
	cells[from.first][from.second]->removeObject();
	obj->setCell(cells[to.first][to.second]);
}