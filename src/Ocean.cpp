#include "Ocean.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <windows.h>
#include <conio.h>

Ocean::Ocean(size_t height, size_t width) :
	height(height),
	width(width) {
	cells = new Cell * [height];
	for (coord_t i = 0; i < height; i++) {
		cells[i] = new Cell[width];
		for (coord_t j = 0; j < width; j++) {
			cells[i][j].init({ i, j }, this);
		}
	}
	srand((unsigned)time(0));
}

Ocean::~Ocean() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			delete cells[i][j].getObject();
		}
		delete[] cells[i];
	}
	delete[] cells;
}

void Ocean::run() {
	while (!_kbhit() && !livingStuff.empty()) {
		print();
		for (auto it = livingStuff.begin(); it != livingStuff.end();) {
			objCounter += (*it)->live((*it)->possibleMoves(cells, height, width), livingStuff);
			if ((*it)->getHealth() <= 0) {
				if ((*it)->getCell()->getObject() == (*it)) {
					(*it)->getCell()->setObject(nullptr);
				}
				delete (*it);
				it = livingStuff.erase(it);
				objCounter--;
			}
			else {
				it++;
			}
		}
		cycle++;
	}
}

void Ocean::print() const {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
	std::cout << "Ocean, iteration #" << cycle << std::endl;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (cells[i][j].getObject() == nullptr) {
				std::cout << '.';
			}
			else {
				std::cout << cells[i][j].getObject()->getSymbol();
			}
		}
		std::cout << std::endl;
	}
	std::cout << "Press any button to stop." << std::endl;
}

Pair* Ocean::findFreeRandomCoord() const {
	if (objCounter >= height * width) {
		std::cout << "Ocean is full." << std::endl;
		return nullptr;
	}
	coord_t x = 0;
	coord_t y = 0;
	do {
		x = rand() % height;
		y = rand() % width;
	} while (cells[x][y].getObject() != nullptr);
	return new Pair{ x, y };
}
