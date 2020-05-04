#include "Ocean.h"
#include "Stone.h"
#include "Prey.h"
#include "Cell.h"
#include "Predator.h"
#include <ctime>
#include <cstdlib>
#include <Windows.h>
#include <iostream>

Ocean::Ocean() : Ocean(5,5){}

Ocean::Ocean(int width, int height) : width(width), height(height) {
    cells = new Cell*[height];
    for (int i = 0; i < height; i++){
        cells[i] = new Cell[width];
		for (int j = 0; j < width; j++) {
			cells[i][j].setLocation(coord{ j, i });
			emptyCells.push_back(cells[i][j].getLocation());
		}
    }
}

int Ocean::getHeight() {
    return height;
}

int Ocean::getWidth() {
    return width;
}

void Ocean::createObjects() {
	srand(time(0));
	int x, y;
	int number = width * height + 1;
	int randomNumber = rand() % number;
	number -= randomNumber;	

	for (int i = 0; i < randomNumber; i++) {
		coord* coordCell = generateCoord();
		Stone* stone = new Stone(*coordCell, this);
		cells[coordCell->y][coordCell->x].setObject(stone);
	}
	
	randomNumber = rand() % number;
	number -= randomNumber;
	for (int i = 0; i < randomNumber; i++) {
		coord* coordCell = generateCoord();
		Prey* prey = new Prey(*coordCell, this);
		prey->birth();
	}
	randomNumber = rand() % number;
	number -= randomNumber;
	for (int i = 0; i < randomNumber; i++) {
		coord* coordCell = generateCoord();
		Predator* predator = new Predator(*coordCell, this);
		predator->birth();
	}
}

coord* Ocean::generateCoord() {
	srand(time(0));	
	int index = rand() % emptyCells.size();
	coord* coordCell = emptyCells[index];
	emptyCells.erase(emptyCells.begin() + index);
	return coordCell;
}

void Ocean::print() {
	system("cls");
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            cells[i][j].printSymbol();
            std::cout << ' ';
        }
        std::cout << std::endl;
    }
}

void Ocean::mainloop() {
	while (true) {
		update();			
		print();
		Sleep(500);
	}
}

void Ocean::update() {
	std::vector<LivingObject*> copyLivingObjects(livingObjects);

	for (int i = 0; i < copyLivingObjects.size(); i++) {
		if (isExist(i, copyLivingObjects[i])) {
			copyLivingObjects[i]->live();
		}
	}
}

Cell* Ocean::getCell(int x, int y) {
	if (x >= 0 && x < width && y >= 0 && y < height) {
		return &cells[y][x];
	}
	return nullptr;
}

Cell* Ocean::getCell(coord* coordinates) {
	return getCell(coordinates->x, coordinates->y);
}

void Ocean::addObject(LivingObject* object) {
	livingObjects.push_back(object);
}

void Ocean::deleteObject(LivingObject* object) {
	for (int i = 0; i < livingObjects.size(); i++) {
		if (livingObjects[i] == object) {
			livingObjects.erase(livingObjects.begin() + i);
			break;
		}
	}	
}

bool Ocean::isExist(int index, LivingObject* object) {
	index = min(index, livingObjects.size() - 1);
	for (int i = 0; i <= index; i++) {
		if (livingObjects[i] == object) {
			return true;
		}
	}
	return false;
}