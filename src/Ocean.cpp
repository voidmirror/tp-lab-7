#include <iostream>
#include <time.h>
//#include "windows.h"
#include "Ocean.h"
#include "Cell.h"
#include "Stone.h"
#include "Prey.h"
#include "Predator.h"


Ocean::Ocean()
{
	cells = new Cell *[N];
	for (int x = 0; x < N; x++)
	{
		cells[x] = new Cell[M];
		for (int y = 0; y < M; y++)
			cells[x][y].init({ x, y }, this);
	}
}

bool Ocean::checkEmptyness(Pair crd){
	if (cells[crd.x][crd.y].getObject() == nullptr)
		return 1;
	return 0;
}

Cell* Ocean::checkAll(Pair crd){
	if (crd.x + 1 < N && this->checkEmptyness({ crd.x + 1, crd.y })) {
		return &cells[crd.x + 1][crd.y];
	}
	else if (crd.y + 1 < M && this->checkEmptyness({ crd.x, crd.y + 1 })) {
		return &cells[crd.x][crd.y + 1];
	}
	else if (crd.x - 1 >= 0 && this->checkEmptyness({ crd.x - 1, crd.y })) {
		return &cells[crd.x - 1][crd.y];
	}
	else if (crd.y - 1 >= 0 && this->checkEmptyness({ crd.x, crd.y - 1 })) {
		return &cells[crd.x][crd.y - 1];
	}
	else return nullptr;
}

Cell* Ocean::checkAllForFood(Pair crd){
	if (crd.x + 1 < N && (this->checkEmptyness({ crd.x + 1, crd.y })) == 0 && this->cells[crd.x + 1][crd.y].getObject()->getType() == ObjType::PREY) {
		return &cells[crd.x + 1][crd.y];
	}
	else if (crd.y + 1 < M && (this->checkEmptyness({ crd.x, crd.y + 1 })) == 0 && this->cells[crd.x][crd.y + 1].getObject()->getType() == ObjType::PREY) {
		return &cells[crd.x][crd.y + 1];
	}
	else if (crd.x - 1 >= 0 && (this->checkEmptyness({ crd.x - 1, crd.y })) == 0 && this->cells[crd.x - 1][crd.y].getObject()->getType() == ObjType::PREY) {
		return &cells[crd.x - 1][crd.y];
	}
	else if (crd.y - 1 >= 0 && (this->checkEmptyness({ crd.x, crd.y - 1 })) == 0 && this->cells[crd.x][crd.y - 1].getObject()->getType() == ObjType::PREY) {
		return &cells[crd.x][crd.y - 1];
	}
	else return nullptr;
}

void Ocean::addObject(Object* obj){
	stuff.push_back(obj);
}

void Ocean::addManyObjects(ObjType objtype, int num){
	srand(time(NULL));
	for (int i = 0; i < num; i++){
		int x = rand() % N;
		int y = rand() % M;
		Object* object = nullptr;
		if (this->cells[x][y].getObject()){
			i -= 1;
			continue;
		}
		switch (objtype){
		case ObjType::PREY:
			object = new Prey();
			break;
		case ObjType::PREDATOR:
			object = new Predator();
			break;
		case ObjType::STONE:
			object = new Stone();
			break;
		}
		cells[x][y].setObject(object);
		object->setCell(&cells[x][y]);
		stuff.push_back(object);
	}

}

void Ocean::removeObject(Object* obj){
	if (obj != nullptr){
		for (int i = 0; i < stuff.size(); i++){
			if (obj == stuff[i]){
				stuff.erase(stuff.begin() + i);
				break;
			}
		}
	}
}

void Ocean::moveObject(Object* obj, Pair newcrd){
	cells[obj->getCell()->getCoord().x][obj->getCell()->getCoord().y].setObject(nullptr);
	cells[newcrd.x][newcrd.y].setObject(obj);
	obj->setCell(&cells[newcrd.x][newcrd.y]);
}

void Ocean::print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (cells[i][j].obj == nullptr) {
				std::cout << "~";
			}
			else {
				switch (cells[i][j].obj->getType()) {
				case ObjType::STONE:
					std::cout << "#";
					break;
				case ObjType::PREY:
					std::cout << "f";
					break;
				case ObjType::PREDATOR:
					std::cout << "S";
					break;
				}
			}
		}
		std::cout << std::endl;
	}
}

void Ocean::run() {
	while (true) {
		for (int i = 0; i < stuff.size(); i++) {
			stuff[i]->live();
		}
		system("CLS");
		print();
		//Sleep(100);
	}
}