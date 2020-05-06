#include "common.h"
#include "object.h"
#include "ocean.h"
#include "cell.h" 
#include <iostream>
#include <vector>
using namespace std;


Ocean::Ocean()
{
	cells = new Cell * [M];
	for (int i = 0; i < M; i++)
	{
		cells[i] = new Cell[N];
	}
	for (size_t i = 0; i < M; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			cells[i][j].init(Pair{ i,j }, this);
		}
	}
}

Ocean::~Ocean() 
{
	for (int i = 0; i < M; i++) {
		delete[] cells[i];
	}
	delete[] cells;
	stuff.clear();
}

void Ocean::print()
{
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (cells[i][j].object == nullptr) {
				std::cout << '.';
				continue;
			}
			switch (cells[i][j].object->getType()) {
			case (ObjType::STONE):
				std::cout << STONE_N;
				break;
			case (ObjType::CORAL):
				std::cout << CORAL_N;
				break;
			case (ObjType::PREY):
				std::cout << PREY_N;
				break;
			case (ObjType::PREDATOR):
				std::cout << PREDATOR_N;
				break;
			default:
				break;
			}
		}
		cout << endl;
	}
}


void Ocean::addObjects(int n, ObjType t)
{
	for (int i = 0; i < n; i++) {
		int x = rand() % M;
		int y = rand() % N;
		Cell* thisCell = &cells[x][y];
		while (thisCell->object != nullptr) {
			x = rand() % M;
			y = rand() % N;
			thisCell = &cells[x][y];
		}
		switch (t) {
		case (ObjType::STONE): {
			Stone* object = new Stone(thisCell);
			thisCell->setObject(object);
			stuff.push_back(object);
			break;
		}
		case (ObjType::CORAL): {
			Coral* object = new Coral(thisCell);
			thisCell->setObject(object);
			stuff.push_back(object);
			break;
		}
		case (ObjType::PREY): {
			Prey* object = new Prey(thisCell);
			thisCell->setObject(object);
			stuff.push_back(object);
			break;
		}
		case (ObjType::PREDATOR): {
			Predator* object = new Predator(thisCell);
			thisCell->setObject(object);
			stuff.push_back(object);
			break;
		}
		default:
			break;
		}
	}
}

void Ocean::run()
{
	for (auto i = 0; i < stuff.size(); i++)
	{
		stuff[i]->live();
	}
	print();
	cout << endl;
	cout << endl;
}

void Ocean::delObj(Cell* c)
{
	for (auto i = stuff.begin(); i != stuff.end(); i++) {
		if ((*i)->getCell() == c) {
			stuff.erase(i);
			return;
		}
	}
}

Cell* Ocean::findEmpty(Pair crd) 
{
	int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1};
	int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1};
	for (int i = 0; i < 8; i++) {
		if ((crd.x + dx[i] >= 0) && (crd.x + dx[i] < M) && (crd.y + dy[i] >= 0) && (crd.y + dy[i] < N)) {
			if (cells[crd.x + dx[i]][crd.y + dy[i]].getObject() == nullptr) {
				return &cells[crd.x + dx[i]][crd.y + dy[i]];
			}
		}
	}
	return nullptr;
}


Cell * Ocean::findPrey(Pair crd) 
{
	int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
	for (int i = 0; i < 8; i++) {
		if ((crd.x + dx[i] >= 0) && (crd.x + dx[i] < M) && (crd.y + dy[i] >= 0) && (crd.y + dy[i] < N)) {
			if (cells[crd.x + dx[i]][crd.y + dy[i]].object != nullptr) {
				if (cells[crd.x + dx[i]][crd.y + dy[i]].object->getType() == ObjType::PREY) {
					return &cells[crd.x + dx[i]][crd.y + dy[i]];
				}
			}
		}
	}
	return nullptr;
}