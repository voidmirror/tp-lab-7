#include <iostream>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include <utility>
#include "common.h"
#include "Ocean.h"
Ocean::Ocean()
{
	cells = new Cell* [N];
	for (int i = 0; i < N; ++i) {
		cells[i] = new Cell[M];
		for (int j = 0; j < M; ++j) {
			Pair crd(i, j);
			cells[i][j].init(crd, this);
		}
	}
}


Ocean::~Ocean()
{
	for (int i = 0; i < N; ++i) {
		delete[] cells[i];
	}
	delete[] cells;
}


int Ocean::getLastId() {
	return lastId;
}

void Ocean::print() const
{
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			std::cout << cells[i][j].getIcon();
		}
		std::cout << std::endl;
	}
}

void Ocean::addObjects(std::list<Object*> objects) {
	for (Object* obj : objects) {
		obj->setId(lastId);
		lastId++;
	}
	stuff.insert(stuff.end(), objects.begin(), objects.end());
}


void Ocean::addObject(Object* object) {
	object->setId(lastId);
	lastId++;
	stuff.push_front(object);
}


void Ocean::run() {
	for (auto it = stuff.begin(); it != stuff.end(); ++it) {
		if (*it != nullptr) {
			(*it)->live();
		}
	}
	stuff.remove_if([](Object* obj) {return obj == nullptr; });
}


void Ocean::randDistribution() {
	const int numOfObjects = N * M;
	Pair crds[numOfObjects];
	srand(static_cast<unsigned int>(time(0)));
	size_t numOfFreeCells = 0;
	for (size_t i = 0; i < N; ++i) {
		for (size_t j = 0; j < M; ++j) {
			if (!cells[i][j].isOccupied()) {
				crds[numOfFreeCells] = Pair(i, j);
				numOfFreeCells++;
			}
			
		}
	}

	size_t restObjNum = 0;
	size_t size = stuff.size();
	for (Object *object : stuff) {
		if (restObjNum <= size) {
			int randIndex = rand() % (numOfFreeCells - restObjNum);
			Pair crd = crds[randIndex];
			cells[crd.x][crd.y].obj = object;
			object->setCell(&cells[crd.x][crd.y]);
			crds[randIndex] = crds[numOfFreeCells - restObjNum - 1];
			crds[numOfObjects - restObjNum - 1] = crd;
			restObjNum++;
		}
		else {
			break;
		}
	}
}


void Ocean::randDistribution(std::list<Object*> newObjs){
	const int numOfObjects = N * M;
	Pair crds[numOfObjects];
	srand(static_cast<unsigned int>(time(0)));
	size_t numOfFreeCells = 0;
	for (size_t i = 0; i < N; ++i) {
		for (size_t j = 0; j < M; ++j) {
			if (!cells[i][j].isOccupied()) {
				crds[numOfFreeCells] = Pair(i, j);
				numOfFreeCells++;
			}

		}
	}

	size_t restObjNum = 0;
	size_t size = stuff.size();
		for (Object *object : newObjs) {
			if (restObjNum <= size) {
				int randIndex = rand() % (numOfFreeCells - restObjNum);
				Pair crd = crds[randIndex];
				cells[crd.x][crd.y].obj = object;
				object->setCell(&cells[crd.x][crd.y]);
				crds[randIndex] = crds[numOfFreeCells - restObjNum - 1];
				crds[numOfObjects - restObjNum - 1] = crd;
				restObjNum++;
			}
			else {
				break;
			}
		}
}


Cell* Ocean::getCell(Pair crd) const{
	return &cells[crd.x][crd.y];
}


void Ocean::killObject(int id){
	for (auto it = stuff.begin(); it != stuff.end(); ++it) {
		if((*it) != nullptr){
			if ((*it)->getId() == id) {
				(*it) = nullptr;
			}
		}
	}

}