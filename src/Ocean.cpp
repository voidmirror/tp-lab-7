#include "Ocean.h"
#include "Prey.h"
#include "Predator.h"
#include "Stone.h"

Ocean::Ocean() {
	cells = new Cell * [N];
	for (size_t i = 0; i < N; i++) {
		cells[i] = new Cell[M];
		for (size_t j = 0; j < M; j++)
			cells[i][j].init(Pair{ i, j }, this);
	}
}

Ocean::~Ocean() {
	for (int i = 0; i < N; i++)
		delete[] cells[i];
	delete[] cells;
	for (auto object : stuff)
		delete object;
}

void Ocean::print() const {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			if (cells[i][j].getObj())
				std::cout << cells[i][j].getObj()->getSymbol();
			else
				std::cout << ".";
		std::cout << "\n";
	}
}

void Ocean::addObjects(ObjType type, unsigned int count) {
	for (int i = 0; i < count; i++) {
		int x = rand() % N;
		int y = rand() % M;

		while (cells[x][y].getObj() != nullptr) {
			x = rand() % N;
			y = rand() % M;
			
		}
		Object* obj = nullptr;

		switch (type) { // for report
		case ObjType::STONE:
			obj = new Stone(&cells[x][y]);
			count_stone++;
			break;
		case ObjType::PREY:
			obj = new Prey(&cells[x][y]);
			count_prey++;
			break;
		case ObjType::PREDATOR:
			obj = new Predator(&cells[x][y]);
			count_predator++;
			break;
		default:
			break;
		}
		this->setStuff(obj);
		cells[x][y].setObject(obj);
	}
		
}

void Ocean::setStuff(Object* obj) {
	stuff.push_back(obj);
}

void Ocean::deleteObject(Object* obj) {
	obj->getCell()->killme();
}

Cell* Ocean::EmptyCellAroundIt(Pair coord) {
	for (int i = 0; i < 20; i++) {
		size_t x = coord.x + rand() % 3 - 1;
		size_t y = coord.y + rand() % 3 - 1;
		if (x < N && y < M)
			if (cells[x][y].getObj() == nullptr)
				return &cells[x][y];
	}
	return nullptr;
}

Cell* Ocean::CellWithPreyAroundIt(Pair coord) {
	for (int i = 0; i < 20; i++) {
		size_t x = coord.x + rand() % 3 - 1;
		size_t y = coord.y + rand() % 3 - 1;
		if (x < N && y < M)
			if (cells[x][y].getObj())
				if (cells[x][y].getObj()->getType() == ObjType::PREY)
					return &cells[x][y];
	}
	return nullptr;
}

void Ocean::run() {
	if (stuff.size() == 0)
		return;
	for (auto it = stuff.begin(); it != stuff.end();) {
		if ((*it)->live() == false) {
			switch ((*it)->getType()) {
			case ObjType::PREDATOR:
				count_predator--;
				break;
			case ObjType::PREY:
				count_prey--;
				break;
			case ObjType::STONE:
				count_stone--;
				break;
			default:
				break;
			}

			deleteObject(*it);
			stuff.erase(it++);
		}
		else
			it++;
	}
}