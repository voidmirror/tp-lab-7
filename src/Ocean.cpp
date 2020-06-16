#include "Ocean.h"
#include "Stone.h"
#include "Prey.h"
#include "Predator.h"

#include <set>
#include <random>
#include <time.h>
#include <iostream>
#include <windows.h>

using namespace std;

int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };

Ocean::Ocean(int stones, int preys, int predators) {
	vector<Cell*>empty(N, nullptr);
	cells.assign(M, empty);
	this->preys = 0;
	this->predators = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cells[i][j] = new Cell({(coord_t)i, (coord_t)j}, this);
		}
	}
	vector<vector<bool>>used(N, vector<bool>(M));
	srand(time(0));
	for (int counter = 0; counter < stones;) {
		int rand_i = rand() % N;
		int rand_j = rand() % M;
		if (!used[rand_i][rand_j]) {
			used[rand_i][rand_j] = true;
			counter++;
			addObject(ObjType::STONE, STONE_LIFESPAN, STONE_REPRODUCTION, STONE_CAPACITY, cells[rand_i][rand_j]);
		}
	}
	for (int counter = 0; counter < preys;) {
		int rand_i = rand() % N;
		int rand_j = rand() % M;
		if (!used[rand_i][rand_j]) {
			used[rand_i][rand_j] = true;
			counter++;
			addObject(ObjType::PREY, PREY_LIFESPAN, PREY_REPRODUCTION, PREY_CAPACITY, cells[rand_i][rand_j]);
		}
	}
	for (int counter = 0; counter < predators;) {
		int rand_i = rand() % N;
		int rand_j = rand() % M;
		if (!used[rand_i][rand_j]) {
			used[rand_i][rand_j] = true;
			counter++;
			addObject(ObjType::PREDATOR, PREDATOR_LIFESPAN, PREDATOR_REPRODUCTION, PREDATOR_CAPACITY, cells[rand_i][rand_j]);
		}
	}
	swap(stuff, nextIteration);
}

void Ocean::printOcean() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			Object* object = cells[i][j]->getObject();
			if (object == nullptr) {
				cout << ".";
			}
			else {
				cout << object->getObjectType();
			}
		}
		cout << '\n';
	}
	for (int i = 0; i < N; i++)cout << "=";
	cout << '\n';
}

void Ocean::run() {
	printOcean();
	random_device rd;
	mt19937 g(rd());
	while (true) {
		shuffle(stuff.begin(), stuff.end(), g);
		Sleep(5000);
		string result = nextStep();
		printOcean();
		if (result != "fine") {
			break;
		}
	}
}

string Ocean::nextStep() {
	nextIteration.clear();
	for (Object* object : stuff) {
		if (object->isAlive()) {
			object->live();
			//printOcean();
			//Sleep(2000);
		}
	}
	vector<Object*>aliveObject;
	vector<Object*>deleteList;
	for (Object* object : stuff) {
		if (object->isAlive()) {
			aliveObject.push_back(object);
		}
		else {
			deleteList.push_back(object);
		}
	}
	for (Object* object : nextIteration) {
		if (object->isAlive()) {
			aliveObject.push_back(object);
		}
		else {
			deleteList.push_back(object);
		}
	}
	stuff.clear();
	nextIteration.clear();
	swap(stuff, aliveObject);
	for (Object* object : deleteList) {
		delete object;
	}
	if (preys == 0 || predators == 0) {
		return "end";
	}
	return "fine";
}

void Ocean::addObject(ObjType type, int lifespan, int reproduction, int capacity, Cell* cell) {
	if (type == ObjType::STONE) {
		Object* newStone = new Stone(cell);
		nextIteration.push_back(newStone);
	}
	else if (type == ObjType::PREY) {
		preys++;
		Object* newPrey = new Prey(cell, PREY_LIFESPAN, PREY_REPRODUCTION);
		nextIteration.push_back(newPrey);
	}
	else if (type == ObjType::PREDATOR) {
		predators++;
		Object* newPredator = new Predator(cell, PREDATOR_LIFESPAN, PREDATOR_REPRODUCTION, PREDATOR_CAPACITY);
		nextIteration.push_back(newPredator);
	}
}

Cell* Ocean::getCell(coord_t x, coord_t y) {
	return cells[x][y];
}

void Ocean::reducePrey() {
	preys--;
}

void Ocean::reducePredators() {
	predators--;
}

Ocean::~Ocean() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			delete cells[i][j];
		}
	}
}
