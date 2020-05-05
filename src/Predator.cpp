#include"Predator.h"
#include"Cell.h"
#include"Ocean.h"
#include <cstdlib>
#include <ctime>
#include<vector>

Move possibleMovesPred[] = { Move(0,-1), Move(0,1),  Move(1,0) , Move(-1,0) };



std::vector<Cell*> getNeighboursPred(Cell* cell) {
	Ocean* currentOcean = cell->getOcean();
	Pair currentCoord = cell->getCoord();
	std::vector<Cell*>neighbours;

	for (Move mv : possibleMovesPred) {
		int newx = currentCoord.x + mv.x;
		int newy = currentCoord.y + mv.y;
		if (newx >= 0 && newy >= 0 && newx < N && newy < M) {
			neighbours.push_back(currentOcean->getCell(Pair(newx, newy)));
		}
	}
	return neighbours;
}


std::vector<Cell*> getFreeCellsPred(std::vector<Cell*> cellsVect) {
	std::vector<Cell*>freeCells;
	for (Cell* cell : cellsVect) {
		if (!cell->isOccupied()) {
			freeCells.push_back(cell);
		}
	}
	return freeCells;
}


std::vector<Cell*> getFreeCellsWithPrey(std::vector<Cell*> cellsVect) {
	std::vector<Cell*>freeCells;
	for (Cell* cell : cellsVect) {
		if (!cell->isOccupied() || cell->getObject()->getType() == ObjType::PREY) {
			freeCells.push_back(cell);
		}
	}
	return freeCells;
}


Cell* newRandCellPred(Cell* curCell) {
	srand(static_cast<unsigned int>(time(0)));
	std::vector<Cell*>neighbours = getNeighboursPred(curCell);
	std::vector<Cell*>freeCells = getFreeCellsPred(neighbours);
	size_t size = freeCells.size();
	if (size > 0) {
		size_t randIndex = rand() % size;
		return freeCells[randIndex];
	}
	else {
		return curCell;
	}
}


Cell* newRandCellWithPrey(Cell* curCell) {
	srand(static_cast<unsigned int>(time(0)));
	std::vector<Cell*>neighbours = getNeighboursPred(curCell);
	std::vector<Cell*>freeCells = getFreeCellsWithPrey(neighbours);
	size_t size = freeCells.size();
	if (size > 0) {
		std::vector<Cell*>cellsWithPrey;
		for (Cell* cell : freeCells) {
			if (cell->getObject() != nullptr) {
				if (cell->getObject()->getType() == ObjType::PREY) {
					cellsWithPrey.push_back(cell);
				}
			}
		}
		if (cellsWithPrey.size() > 0) {
			size_t randIndex = rand() % cellsWithPrey.size();
			return cellsWithPrey[randIndex];
		}
		size_t randIndex = rand() % size;
		return freeCells[randIndex];
	}
	else {
		return curCell;
	}
}


bool movePred(Cell* currentCell, Cell* newCell) {
	bool flagEat = false;
	
	if (newCell->getObject() != nullptr) {
		if (newCell->getObject()->getType() == ObjType::PREY) {
			newCell->getOcean()->killObject(newCell->getObject()->getId());
			newCell->killMe();
			flagEat = true;
		}
	}
	else {

	}
	
	
	Object* bufObj = currentCell->getObject();
	bufObj->setCell(newCell);
	currentCell->killMe();
	newCell->setObject(bufObj);
	return flagEat;
}


void makeChildPred(Cell* cellForChild) {
	Object* child = Object::createObject(ObjType::PREDATOR);
	cellForChild->getOcean()->addObject(child);
	cellForChild->setObject(child);
	child->setCell(cellForChild);
}


void Predator::live() {
	Cell* currentCell = this->cell;
	Cell* newCell = newRandCellWithPrey(currentCell);
	bool ifAte = movePred(currentCell, newCell);

	if (ifAte){
		Cell* cellForChild = newRandCellPred(newCell);
		makeChildPred(cellForChild);
		ltWithoutEat = PREDATOR_LT_WITHOUT_EAT;
	}
	
	ltWithoutEat--;
	restLifetime--;
	if (restLifetime == 0 || ltWithoutEat == 0) {
		newCell->getOcean()->killObject(newCell->getObject()->getId());
		newCell->killMe();
	}
}