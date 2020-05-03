#include "Ocean.h"
#include "Stone.h"
#include "Prey.h"
#include "Predator.h"
#include <chrono>
#include <thread>

Ocean::Ocean() {
	cells = new Cell *[N];
	for (int i = 0; i < N; i++) {
		cells[i] = new Cell[M];
		}
}

void Ocean::init() {
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
		cells[i][j].init(Pair{ (size_t)j, (size_t)i }, this);
	}
}

Ocean::~Ocean() {
	for (int i = 0; i < N; i++) {
		delete[] cells[i];
	}
	delete[] cells;
	for (auto obj = stuff.begin(); obj != stuff.end(); obj++) {
		delete* obj;
	}
}

void Ocean::print() const {
	int preyCnt = 0;
	int predatorCnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			if (cells[i][j].getObject()) {
				std::cout << cells[i][j].getObject()->getName();
				if (cells[i][j].getObject()->getName() == PREY_TILE) {
					preyCnt++;
				}
				if (cells[i][j].getObject()->getName() == PREDATOR_TILE) {
					predatorCnt++;
				}
			}
			else {
				std::cout << ".";
			}
		std::cout << std::endl;
	}
	if (preyCnt == 0) {
		system("cls");
		std::cout << "Predators survived" << std::endl;
		exit(0);
	}
	if (predatorCnt == 0) {
		system("cls");
		std::cout << "Preys survived" << std::endl;
		exit(0);
	}
}

void Ocean::addObjects(int stoneNum, int preyCnt, int predatorCnt) {
	while (stoneNum || preyCnt || predatorCnt) {
		if (stoneNum) {
			size_t x = rand() % M;
			size_t y = rand() % N;
			if (!cells[y][x].getObject()) {
				Object* object = new Stone(&cells[y][x]);
				cells[y][x].setObject(object);
				stuff.push_back(object);
				stoneNum--;
			}
		}
		if (preyCnt) {
			size_t x = rand() % M;
			size_t y = rand() % N;
			if (!cells[y][x].getObject()) {
				Object* object = new Prey(&cells[y][x]);
				cells[y][x].setObject(object);
				stuff.push_back(object);
				preyCnt--;
			}
		}
		if (predatorCnt) {
			size_t x = rand() % M;
			size_t y = rand() % N;
			if (!cells[y][x].getObject()) {
				Object* object = new Predator(&cells[y][x]);
				cells[y][x].setObject(object);
				stuff.push_back(object);
				predatorCnt--;
			}
		}
	}
}

void Ocean::run(int speed) {
	while (true) {
		if (stuff.size() == 0) {
			break;
		}
		for (int i = 0; i < stuff.size(); i++) {
			stuff[i]->live();
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(speed));
		system("cls");
		print();
	}
}

void Ocean::addObject(Object* object) {
	stuff.push_back(object);
}

void Ocean::deleteObject(Object* object) {
	for (auto item = stuff.begin(); item != stuff.end(); item++) {
		if (*item == object) {
			(*item)->getCell()->clearCell();
			delete *item;
			stuff.erase(item);
			break;
		}
	}
}

Cell* Ocean::getFreeCell(Pair coord) {
	std::vector<char> xArray = { 0,0,1,1,1,-1,-1,-1 };
	std::vector <char> yArray = { -1,1,0,1,-1,0,1,-1 };
	while (xArray.size()) {
		char i = rand() % xArray.size();
		if (coord.x + xArray[i] >= 0 && coord.x + xArray[i] < M && coord.y + yArray[i] >= 0 && coord.y + yArray[i] < N) {
			if (cells[coord.y + yArray[i]][coord.x + xArray[i]].getObject() == nullptr) {
				return &cells[coord.y + yArray[i]][coord.x + xArray[i]];
			}
		}
		xArray.erase(xArray.begin() + i);
		yArray.erase(yArray.begin() + i);
	}
	return nullptr;
}


Cell* Ocean::getPreyCell(Pair coord) {
	std::vector<char> xArray = { 0, 0, 1, 1, 1, -1, -1, -1 };
	std::vector <char> yArray = { -1, 1, 0, 1, -1, 0, 1, -1 };
	while (xArray.size()) {
		char i = rand() % xArray.size();
		if (coord.x + xArray[i] >= 0 && coord.x + xArray[i] < M && coord.y + yArray[i] >= 0 && coord.y + yArray[i] < N)	{
			if (cells[coord.y + yArray[i]][coord.x + xArray[i]].getObject() != nullptr && cells[coord.y + yArray[i]][coord.x + xArray[i]].getObject()->getName() == PREY_TILE) {
				return &cells[coord.y + yArray[i]][coord.x + xArray[i]];
			}
		}
		xArray.erase(xArray.begin() + i);
		yArray.erase(yArray.begin() + i);
	}
	return nullptr;
}