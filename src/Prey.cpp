#include"Prey.h"
#include"Cell.h"
#include"Ocean.h"
#include <cstdlib>
#include <ctime>
#include<vector>

Move possibleMovesPrey[] = { Move(0,-1), Move(0,1),  Move(1,0) , Move(-1,0) };


std::vector<Cell*> getNeighboursPrey(Cell* cell) {
	Ocean* currentOcean = cell->getOcean();
	Pair currentCoord = cell->getCoord();
	std::vector<Cell*>neighbours;

	for (Move mv : possibleMovesPrey) {
		int newx = currentCoord.x + mv.x;
		int newy = currentCoord.y + mv.y;
		if (newx >= 0 && newy >= 0 && newx < N && newy < M) {
			neighbours.push_back(currentOcean->getCell(Pair(newx, newy)));
		}
	}
	return neighbours;
}


std::vector<Cell*> getFreeCellsPrey(std::vector<Cell*> cellsVect) {
	std::vector<Cell*>freeCells;
	for (Cell* cell : cellsVect) {
		if (!cell->isOccupied()) {
			freeCells.push_back(cell);
		}
	}
	return freeCells;
}


Cell* newRandCellPrey(Cell* curCell){
	srand(static_cast<unsigned int>(time(0)));
	std::vector<Cell*>neighbours = getNeighboursPrey(curCell);
	std::vector<Cell*>freeCells = getFreeCellsPrey(neighbours);
	size_t size = freeCells.size();
	if (size > 0) {
		size_t randIndex = rand() % size;
		return freeCells[randIndex];
	}
	else {
		return curCell;
	}
}


void movePrey(Cell* currentCell, Cell* newCell) {
	Object* bufObj = currentCell->getObject();
	bufObj->setCell(newCell);
	currentCell->killMe();
	newCell->setObject(bufObj);
}


void makeChildPrey(Cell* cellForChild) {
	if (cellForChild->getObject() == nullptr) {
		Object* child = Object::createObject(ObjType::PREY);
		cellForChild->getOcean()->addObject(child);
		cellForChild->setObject(child);
		child->setCell(cellForChild);
	}
}


void Prey::live() {
	Cell* currentCell = this->cell;
	Cell* newCell = newRandCellPrey(currentCell);

	if ((newCell->getCoord().x != currentCell->getCoord().x) ||(newCell->getCoord().y != currentCell->getCoord().y)){
		movePrey(currentCell, newCell);
	}
	
	if (restLifetime % REPR_PERIOD == REPR_PERIOD - 1) {
		Cell* cellForChild = newRandCellPrey(newCell);
		if ((cellForChild->getCoord().x != newCell->getCoord().x) || (cellForChild->getCoord().y != newCell->getCoord().y)) {
			makeChildPrey(cellForChild);
		}
	}
	restLifetime--;
	if (restLifetime == 0) {
		newCell->getOcean()->killObject(newCell->getObject()->getId());
		newCell->killMe();
	}
}