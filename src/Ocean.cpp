#include "Ocean.h"
#include "Stone.h"
#include "Prey.h"
#include "Predator.h"
#include "windows.h"
#include <iostream>
#include <vector>



Ocean::Ocean() {
	cells = new Cell * [rows]; 
	for (int i = 0; i < rows; i++) {
		cells[i] = new Cell [columns]; 
		for (int j = 0; j < columns; j++) {
			cells[i][j].init({ i, j }, this);
		}
	}
}
void Ocean::delObj(Object* object) {
	for (auto item = stuff.begin(); item != stuff.end(); item++) {
		if (*item == object) {
			(*item)->getCell()->killMe();
			delete* item;
			stuff.erase(item);
			break;
		}
	}
}
void Ocean::addObjs(ObjType type, int q) {
	for (int k = 0; k < q; k++) {
		Cell* cellAdd = &cells[rand() % rows][rand() % columns];
		while (cellAdd->getObj() != nullptr)
			cellAdd = &cells[rand() % rows][rand() % columns];
		switch (type) {
		case (ObjType::STONE): {
			Stone* stone = new Stone();
			stone->setCell(cellAdd);
			cellAdd->setObj(stone);
			stuff.push_back(stone);
			break;
		}
		case (ObjType::PREY): {
			Prey* prey = new Prey();
			prey->setCell(cellAdd);
			cellAdd->setObj(prey);
			stuff.push_back(prey);
			break;
		}
		case (ObjType::PREDATOR): {
			Predator* predator = new Predator();
			predator->setCell(cellAdd);
			cellAdd->setObj(predator);
			stuff.push_back(predator);
			break;
		}
		default:
			break;
		}
	}
}

void Ocean::print()  {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (cells[i][j].getObj() == nullptr) {
				std::cout<< '~';
				continue;
			}
			ObjType type = cells[i][j].getObj()->getType();
			if (type == ObjType::PREY) std::cout << "o";
			else if (type == ObjType::PREDATOR) std::cout << "F";
			else if (type == ObjType::STONE) std::cout << "#";
		}
		std::cout << "\n";
	}
}

Cell* Ocean::freeCellcheck(pair crd) {
	std::vector<pair> newcrd = { { 0,-1} ,{0,1}, {1,0}, {1,1}, {1,-1}, {-1,0}, {-1,1}, {-1,-1} };
	int w = 9;

	while (--w) {
		int i = rand() % w;
		int xnew = crd.x + newcrd[i].x;
		int ynew = crd.y + newcrd[i].y;

		if (xnew >= 0 && xnew < rows && ynew >= 0 && ynew < columns) {
			if (cells[xnew][ynew].getObj() == nullptr)
				return &cells[xnew][ynew];
		}
		newcrd.erase(newcrd.begin() + i);
		
	}
	return nullptr;

}

Cell* Ocean::preyCellcheck(pair crd) {
	std::vector<pair> newcrd = { { 0,-1} ,{0,1}, {1,0}, {1,1}, {1,-1}, {-1,0}, {-1,1}, {-1,-1} };
	int w = 9;

	while (--w) {
		
		int i = rand() % w;
		int xnew = crd.x + newcrd[i].x;
		int ynew = crd.y + newcrd[i].y;

		if (xnew >= 0 && xnew < rows && ynew >= 0 && ynew < columns) {
			if (cells[xnew][ynew].getObj() != nullptr && cells[xnew][ynew].getObj()->getType() == ObjType::PREY) {
				return &cells[xnew][ynew];
			}
		}
		newcrd.erase(newcrd.begin() + i);
	}
	return nullptr;

}
void Ocean::run() {
	int preyN, predatorN;
	int iteration = 1;
	ObjType type;
	while (1) {
		preyN = 0;
		predatorN = 0;
		for (int i = 0; i < stuff.size(); i++) {
			type = stuff[i]->getType();
			if (type == ObjType::PREY) preyN++;
			else if (type == ObjType::PREDATOR) predatorN++;
		}

		if (preyN == 0) {
			std::cout << "PREDATORS WON";
			break;
		}
		else if (predatorN == 0){
			std::cout << "PREYS WON";
			break;}

		for (int i = 0; i < stuff.size(); i++)
			stuff[i]->live();

		Sleep(100);
		system("cls");
		print();
	}
}