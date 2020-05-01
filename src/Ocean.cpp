#include "Ocean.h" //fix
#include "Object.h"
#include "Stone.h"
#include "Prey.h"
#include "Predator.h"

#include <iostream>
#include <random>
#include <ctime>

using namespace std;

Ocean::Ocean() {
	cells = new Cell * [N];
	for (int i = 0; i < N; i++) {
		cells[i] = new Cell[M];
		for (int j = 0; j < M; j++)
			cells[i][j].Init(Pair{ i, j }, this);
	}
};

void Ocean::AddStuff(Object* object) {
	stuff.push_back(object);
};

void Ocean::Print() const{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (cells[i][j].GetObject()) {
				cout << cells[i][j].GetObject()->GetSymbol();
			}
			else {
				cout << '.';
			}
		}
		cout << endl;
	}
};

void Ocean::AddObjects(unsigned int n, ObjectType type){
	while (n > 0){
		unsigned int x = rand() % M;
		unsigned int y = rand() % N;
		if (cells[y][x].GetObject())
			continue;
		else {
			Object* newchild = nullptr;
			switch (type){
			case ObjectType::STONE:
				newchild = new Stone(&cells[y][x]);
				break;
			case ObjectType::PREY:
				newchild = new Prey(&cells[y][x]);
				break;
			case ObjectType::PREDATOR:
				newchild = new Predator(&cells[y][x]);
				break;
			}
			cells[y][x].SetObject(newchild);
			stuff.push_back(newchild);
			n--;
		}
	}
};

bool Ocean::DeleteStuff(Object* object) {
	if (object->GetLifetime() == 0) {
		object->GetCell()->KillMe();
		return false;
	}
	return true;
};

Cell* Ocean::FindEmptyCell(Pair cords) {
	random_device ran;
	int c1 = cords.x + ran() % 3 - 1;
	int c2 = cords.y + ran() % 3 - 1;
	if (c2 < N && c2 < M) {
		if (cells[c2][c2].GetObject() == nullptr)
			return &cells[c2][c2];

	}
	return nullptr;
};

Cell* Ocean::FindPreyCell(Pair cords) {
	random_device ran;
	int i = 0;
	while (i != 8) {
		int c1 = cords.x + ran() % 3 - 1;
		int c2 = cords.y + ran() % 3 - 1;
		if (c1 < N && c2 < M) {
			if (cells[c1][c2].GetObject() && cells[c1][c2].GetObject()->GetType() == ObjectType::PREY)
				return  &cells[c1][c2];
		}
		i++;
	}
	return nullptr;
};

void Ocean::Run(){
	while (true){

		system("cls");
		clock_t time = clock();
		Print();

		while (clock() < time + CLOCKS_PER_SEC / 10);
		list<Object*>::iterator i = stuff.begin();
		while (i != stuff.end()){
			bool IsLive = DeleteStuff(*i);
			if (!IsLive){
				stuff.erase(i++);
			}
			else{
				(*i)->Live();
				++i;
			}
		}

	}
};

Ocean::~Ocean(){
	for (int i = 0; i < N; i++)
		delete[] cells[i];
	delete[] cells;
	for (auto i = stuff.begin(); i != stuff.end(); ++i)
		delete* i;
};

