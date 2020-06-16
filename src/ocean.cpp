#include "ocean.h"
#include "stone.h"
#include "prey.h"
#include "predator.h"
#include <time.h>

Ocean::Ocean() {
	cells = new Cell * [N];
	for (size_t i = 0; i < N; i++) {
		cells[i] = new Cell[M];
		for (size_t j = 0; j < M; j++)
			cells[i][j].init(Pair{ j, i }, this);
	}
}

Ocean::~Ocean() {
	for (size_t i = 0; i < N; i++)
		delete[] cells[i];
	delete[] cells;
	for (auto obj = stuff.begin(); obj != stuff.end(); ++obj)
		delete* obj;
}

void Ocean::print() const {
	for (size_t i = 0; i < N; i++) {
		for (size_t j = 0; j < M; j++)
			cout << (cells[i][j].getObject() ? cells[i][j].getObject()->getName() : '-');
		cout << endl;
	}
}

void Ocean::addObjects(int count) {
	while (count > 0) {
		coord_t x = rand() % M;
		coord_t y = rand() % N;	
		if (cells[y][x].getObject()) // Занята ли ячейка?
			continue;
		else {
			int object_type = rand() % 3 + 1;
			Object* object = nullptr;
			switch (object_type) {
				case 1:
					object = new Stone(&cells[y][x]);
					break;
				case 2:
					object = new Prey(&cells[y][x]);
					break;
				case 3:
					object = new Predator(&cells[y][x]);
					break;
			}
			cells[y][x].setObject(object);
			stuff.push_back(object);
			count--;
		}
	}
}

void Ocean::removeObjects() {
	for (int index = 0; index < stuff.size(); index++) {
		if (stuff[index]->getLiveTime() <= 0) {
			/*if (stuff[index]->getName() == PREY_N)
				Prey::death_counter();*/
			delete stuff[index];
			stuff.erase(stuff.begin() + index);
			index--;
		}
	}
}

void Ocean::run(int speed) {
	while (1) {
		if (stuff.size() == 0)
			break;
		for (int index = 0; index < stuff.size(); index++)
			stuff[index]->live();
		clock_t now = clock();
		while (clock() < now + CLOCKS_PER_SEC - 100 * speed);
		system("cls");
		print();
		removeObjects();
	}
}

Cell* Ocean::getFreeCell(Pair crd) {
	vector<int> random = { 1, 2, 3, 4, 5, 6, 7, 8 };
	while (random.size() != 0) {
		int index = rand() % random.size(); 
		int step = random[index];
		random.erase(random.begin() + index);
		/*
			123
			8-4
			765

			 MM
			N
			N
		*/
		int x = 0;
		int y = 0;
		switch (step) {
		case 1:
			x = crd.x - 1;
			y = crd.y - 1;
			if ((x >= 0) && (y >= 0))
				if (cells[crd.y - 1][crd.x - 1].getObject() == nullptr)
					return &cells[crd.y - 1][crd.x - 1];
			break;
		case 2:
			x = crd.x;
			y = crd.y - 1;
			if (y >= 0)
				if (cells[crd.y - 1][crd.x].getObject() == nullptr)
					return &cells[crd.y - 1][crd.x];
			break;
		case 3:
			x = crd.x + 1;
			y = crd.y - 1;
			if (x < M && y >= 0)
				if (cells[crd.y - 1][crd.x + 1].getObject() == nullptr)
					return &cells[crd.y - 1][crd.x + 1];
			break;
		case 4:
			x = crd.x + 1;
			y = crd.y;
			if (x < M)
				if (cells[crd.y][crd.x + 1].getObject() == nullptr)
					return &cells[crd.y][crd.x + 1];
			break;
		case 5:
			x = crd.x + 1;
			y = crd.y + 1;
			if (x < M && y < N)
				if (cells[crd.y + 1][crd.x + 1].getObject() == nullptr)
					return &cells[crd.y + 1][crd.x + 1];
			break;
		case 6:
			x = crd.x;
			y = crd.y + 1;
			if (y < N)
				if (cells[crd.y + 1][crd.x].getObject() == nullptr)
					return &cells[crd.y + 1][crd.x];
			break;
		case 7:
			x = crd.x - 1;
			y = crd.y + 1;
			if (x >= 0 && y < N)
				if (cells[crd.y + 1][crd.x - 1].getObject() == nullptr)
					return &cells[crd.y + 1][crd.x - 1];
			break;
		case 8:
			x = crd.x - 1;
			y = crd.y;
			if (x >= 0)
				if (cells[crd.y][crd.x - 1].getObject() == nullptr)
					return &cells[crd.y][crd.x - 1];
			break;
		default:
			return nullptr;
		}
	}
	// Если все клетки заняты
	return &cells[crd.y][crd.x];
}

void Ocean::addChild(Object* object) {
	stuff.push_back(object);
}

Cell* Ocean::hunting(Pair crd) {
	vector<int> victims; // Позиции, на которых находятся жертвы
	for (size_t i = 1; i <= 8; i++) {
		int x = 0;
		int y = 0;
		switch (i) {
		case 1:
			x = crd.x - 1;
			y = crd.y - 1;
			if ((x >= 0) && (y >= 0))
				if (cells[y][x].getObject())
					if (cells[y][x].getObject()->getName() == PREY_N)
						victims.push_back(i);
			break;
		case 2:
			x = crd.x;
			y = crd.y - 1;
			if (y >= 0)
				if (cells[y][x].getObject())
					if (cells[y][x].getObject()->getName() == PREY_N)
						victims.push_back(i);
			break;
		case 3:
			x = crd.x + 1;
			y = crd.y - 1;
			if (x < M && y >= 0)
				if (cells[y][x].getObject())
					if (cells[y][x].getObject()->getName() == PREY_N)
						victims.push_back(i);
			break;
		case 4:
			x = crd.x + 1;
			y = crd.y;
			if (x < M)
				if (cells[y][x].getObject())
					if (cells[y][x].getObject()->getName() == PREY_N)
						victims.push_back(i);
			break;
		case 5:
			x = crd.x + 1;
			y = crd.y + 1;
			if (x < M && y < N)
				if (cells[y][x].getObject())
					if (cells[y][x].getObject()->getName() == PREY_N)
						victims.push_back(i);
			break;
		case 6:
			x = crd.x;
			y = crd.y + 1;
			if (y < N)
				if (cells[y][x].getObject())
					if (cells[y][x].getObject()->getName() == PREY_N)
						victims.push_back(i);
			break;
		case 7:
			x = crd.x - 1;
			y = crd.y + 1;
			if (x >= 0 && y < N)
				if (cells[y][x].getObject())
					if (cells[y][x].getObject()->getName() == PREY_N)
						victims.push_back(i);
			break;
		case 8:
			x = crd.x - 1;
			y = crd.y;
			if (x >= 0)
				if (cells[y][x].getObject())
					if (cells[y][x].getObject()->getName() == PREY_N)
						victims.push_back(i);
			break;
		}
	}
	if (victims.size() != 0) {
		int kill_index = rand() % victims.size();
		switch (victims[kill_index]) {
		case 1:
			return &cells[crd.y - 1][crd.x - 1];
		case 2:
			return &cells[crd.y - 1][crd.x];
		case 3:
			return &cells[crd.y - 1][crd.x + 1];
		case 4:
			return &cells[crd.y][crd.x + 1];
		case 5:
			return &cells[crd.y + 1][crd.x + 1];
		case 6:
			return &cells[crd.y + 1][crd.x];
		case 7:
			return &cells[crd.y + 1][crd.x - 1];
		case 8:
			return &cells[crd.y][crd.x - 1];
		default:
			return nullptr;
		}
	}
	else return nullptr;
}