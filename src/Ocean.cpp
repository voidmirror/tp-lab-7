#include <iostream>
#include <time.h>

#include "Ocean.h"
#include "Stone.h"
#include "Prey.h"
#include "Predator.h"

Ocean::Ocean() {
	cells = new Cell * [M];
	for (int i = 0; i < M; i++) {
		cells[i] = new Cell[N]; 
		for (int j = 0; j < N; j++) {
			cells[i][j].create({ i, j }, this); 
		}
	}
}

bool Ocean::isCellEmpty(Pair coordinates) {
	if (cells[coordinates.x][coordinates.y].getObject() == nullptr) {
		return 1;
	}
	else return 0;
}

Cell* Ocean::checkPrey(Pair coordinates) {
	if (coordinates.x - 1 >= 0 && not this->isCellEmpty({ coordinates.x - 1, coordinates.y }) 
		&& this->cells[coordinates.x - 1][coordinates.y].getObject()->getType() == PREY) {
		return &cells[coordinates.x - 1][coordinates.y];
	}
	else if (coordinates.x + 1 < M && not this->isCellEmpty({ coordinates.x + 1, coordinates.y })
		&& this->cells[coordinates.x + 1][coordinates.y].getObject()->getType() == PREY) {
		return &cells[coordinates.x + 1][coordinates.y];
	}
	else if (coordinates.y + 1 < N && not this->isCellEmpty({ coordinates.x, coordinates.y + 1 }) 
		&& this->cells[coordinates.x][coordinates.y + 1].getObject()->getType() == PREY) {
		return &cells[coordinates.x][coordinates.y + 1];
	}
	else if (coordinates.y - 1 >= 0 && not this->isCellEmpty({ coordinates.x, coordinates.y - 1 }) 
		&& this->cells[coordinates.x][coordinates.y - 1].getObject()->getType() == PREY) {
		return &cells[coordinates.x][coordinates.y - 1];
	}
	else return nullptr;
}

Cell* Ocean::checkCells(Pair coordinates) {
	if (coordinates.x - 1 >= 0 && this->isCellEmpty({ coordinates.x - 1, coordinates.y })) {
		return &cells[coordinates.x - 1][coordinates.y];
	}
	else if (coordinates.y + 1 < N && this->isCellEmpty({ coordinates.x, coordinates.y + 1})) {
		return &cells[coordinates.x][coordinates.y + 1];
	}
	else if (coordinates.x + 1 < M && this->isCellEmpty({ coordinates.x, coordinates.y + 1})) {
		return &cells[coordinates.x + 1][coordinates.y];
	}
	else if (coordinates.y - 1 >= 0 && this->isCellEmpty({ coordinates.x, coordinates.y - 1 })) {
		return &cells[coordinates.x][coordinates.y - 1];
	}
	else return nullptr;
}

void Ocean::moveObject(Pair coordinates, Object* object) {
	Pair oldCoordinates = object->getCell()->getCoordinates();
	cells[oldCoordinates.x][oldCoordinates.y].setObject(nullptr);
	cells[coordinates.x][coordinates.y].setObject(object);
	object->setCell(&cells[coordinates.x][coordinates.y]);
}

void Ocean::addObject(ObjectType Objectype, Pair coordinates) {
	Object* newObject; 
	if (cells[coordinates.x][coordinates.y].object == nullptr) {
		switch (Objectype) {
		case STONE:

			newObject = new Stone();
			newObject->setCell(&cells[coordinates.x][coordinates.y]); 
			cells[coordinates.x][coordinates.y].object = newObject;
			oceanObjects.push_back(newObject);
			this->stones++;
			break;
		case PREDATOR:

			newObject = new Predator();
			newObject->setCell(&cells[coordinates.x][coordinates.y]);
			cells[coordinates.x][coordinates.y].object = newObject;
			oceanObjects.push_back(newObject);
			break;
		case PREY:

			newObject = new Prey();
			newObject->setCell(&cells[coordinates.x][coordinates.y]); 
			cells[coordinates.x][coordinates.y].object = newObject;
			oceanObjects.push_back(newObject);
			break;
		}

	}
}

void Ocean::deleteObject(Object* object) {
	if (object != nullptr) {
		for (int i = 0; i < oceanObject.size(); i++) {
			if (object == oceanObject[i]) {
				oceanObject.erase(oceanObject.begin() + i);
				return;
			}
		}
	}
}

void Ocean::addAll(int stones, int preys, int predators) {
	srand(time(NULL));
	if (stones + preys + predators <= N * M) {
		for (int i = 0; i < stones; i++) {
			addObject(STONE, { rand() % M, rand() % N });
		}

		for (int i = 0; i < preys; i++) {
			addObject(PREY, { rand() % M, rand() % N });
		}

		for (int i = 0; i < predators; i++) {
			addObject(PREDATOR, { rand() % M, rand() % N });
		}
	}
	else std::cout << "FULL" << std::endl;
}

void Ocean::print() {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (cells[i][j].object == nullptr) {
				std::cout << "."; 
			}
			else {
				switch (cells[i][j].object->getType()) {
				case STONE: 
					std::cout << "s"; 
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
	while (true) {
		for (int i = 0; i < oceanObjects.size(); i++) {
			oceanObjects[i]->exist(); 
		}
		system("CLS");
		print();
		if (oceanObjects.size() == stones) 
			break; 
	}
	std::cout << "Everything id dead. " << std::endl;
}