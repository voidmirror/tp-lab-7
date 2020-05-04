#include <iostream>
#include <time.h>
//#include <windows.h> 
#include "Ocean.h"
#include "Stone.h"
#include "Prey.h"
#include "Predator.h"

Ocean::Ocean() {
	cells = new Cell * [M]; // creating a column of pointers of the size of M
	for (int i = 0; i < M; i++) {
		cells[i] = new Cell[N]; // every pointer in the array of pointers points to a row of N Cells 
		for (int j = 0; j < N; j++) {
			cells[i][j].init({ i, j }, this); // initializing all the cells
		}
	}
}

bool Ocean::isCellEmpty(Pair crd) {
	if (cells[crd.x][crd.y].getObj() == nullptr) {
		return 1;
	}
	else return 0;
}

Cell* Ocean::checkForPreyAround(Pair crd) { // checks if there is any prey object around the crd
	if (crd.x - 1 >= 0 && not this->isCellEmpty({ crd.x - 1, crd.y }) && this->cells[crd.x - 1][crd.y].getObj()->getType() == PREY) {
		return &cells[crd.x - 1][crd.y];
	}
	else if (crd.y + 1 < N && not this->isCellEmpty({ crd.x, crd.y + 1 }) && this->cells[crd.x][crd.y + 1].getObj()->getType() == PREY) {
		return &cells[crd.x][crd.y + 1];
	}
	else if (crd.x + 1 < M && not this->isCellEmpty({ crd.x + 1, crd.y }) && this->cells[crd.x + 1][crd.y].getObj()->getType() == PREY) {
		return &cells[crd.x + 1][crd.y];
	}
	else if (crd.y - 1 >= 0 && not this->isCellEmpty({ crd.x, crd.y - 1 }) && this->cells[crd.x][crd.y - 1].getObj()->getType() == PREY) {
		return &cells[crd.x][crd.y - 1];
	}
	else return nullptr;
}

Cell* Ocean::checkAround(Pair crd) {
	if (crd.x - 1 >= 0 && this->isCellEmpty({ crd.x - 1, crd.y })) {
		return &cells[crd.x - 1][crd.y];
	}
	else if (crd.y + 1 < N && this->isCellEmpty({ crd.x, crd.y + 1})) {
		return &cells[crd.x][crd.y + 1];
	}
	else if (crd.x + 1 < M && this->isCellEmpty({ crd.x, crd.y + 1})) {
		return &cells[crd.x + 1][crd.y];
	}
	else if (crd.y - 1 >= 0 && this->isCellEmpty({ crd.x, crd.y - 1 })) {
		return &cells[crd.x][crd.y - 1];
	}
	else return nullptr;
}

void Ocean::moveObj(Pair new_crd, Object* obj_p) {
	Pair old_crd = obj_p->getCell()->getCrd();
	cells[old_crd.x][old_crd.y].setObj(nullptr);
	cells[new_crd.x][new_crd.y].setObj(obj_p);
	obj_p->setCell(&cells[new_crd.x][new_crd.y]);
}

void Ocean::addObj(ObjType type, Pair coord) {
	Object* new_obj_p; // new object pointer
	if (cells[coord.x][coord.y].obj == nullptr) {
		switch (type) {
		case STONE:
			new_obj_p = new Stone();
			new_obj_p->setCell(&cells[coord.x][coord.y]); 
			cells[coord.x][coord.y].obj = new_obj_p;
			stuff.push_back(new_obj_p);
			this->stone_q++;
			break;
		case PREDATOR:
			new_obj_p = new Predator();
			new_obj_p->setCell(&cells[coord.x][coord.y]);
			cells[coord.x][coord.y].obj = new_obj_p;
			stuff.push_back(new_obj_p);
			break;
		case PREY:
			new_obj_p = new Prey();
			new_obj_p->setCell(&cells[coord.x][coord.y]); 
			cells[coord.x][coord.y].obj = new_obj_p;
			stuff.push_back(new_obj_p);
			break;
		}

	}
}

void Ocean::removeObj(Object* obj_p) {
	if (obj_p != nullptr) {
		for (int i = 0; i < stuff.size(); i++) {
			if (obj_p == stuff[i]) {
				stuff.erase(stuff.begin() + i);
				return;
			}
		}
	}
}

void Ocean::addAll(int stone_q, int prey_q, int predator_q) {
	srand(time(NULL));
	if (stone_q + prey_q + predator_q <= N * M) {
		for (int i = 0; i < stone_q; i++) {
			addObj(STONE, { rand() % M, rand() % N });
		}

		for (int i = 0; i < prey_q; i++) {
			addObj(PREY, { rand() % M, rand() % N });
		}

		for (int i = 0; i < predator_q; i++) {
			addObj(PREDATOR, { rand() % M, rand() % N });
		}
	}
	else std::cout << "Too many objects!" << std::endl;
}

void Ocean::print() {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (cells[i][j].obj == nullptr) {
				std::cout << "~"; // this character represents water (empty cell)
			}
			else {
				switch (cells[i][j].obj->getType()) {
				case STONE: 
					std::cout << "#"; 
					break;
				case PREY: 
					std::cout << "f";
					break;
				case PREDATOR: 
					std::cout << "S";
					break;
				}
			}
		}
		std::cout << std::endl;
	}
} 

void Ocean::run() {
	while (1) {
		for (int i = 0; i < stuff.size(); i++) {
			stuff[i]->live(); 
		}
		system("CLS");
		print();
		//Sleep(50);
		if (stuff.size() == stone_q) break; // it means that there is nothing left but stones, thus there is no need to continue the simulation
	}
	std::cout << "Everyone died, the simulation has ended " << std::endl;
}