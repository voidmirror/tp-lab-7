#include "Prey.h"
#include <iostream>

Prey::Prey(Cell* cell) :
	LivingObject(cell) {
	health = 10;
}

std::vector<Cell*> Prey::possibleMoves(Cell** cellsArray, int height, int width) const {
	std::vector<Cell*> moves;
	if (health > 0) {
		Pair currentCoord = this->getCell()->getCoord();
		std::vector<coord_t> xVariants;
		std::vector<coord_t> yVariants;

		if (currentCoord.x > 0) {
			xVariants.push_back(currentCoord.x - 1);
		}
		xVariants.push_back(currentCoord.x);
		if (currentCoord.x < height - 1) {
			xVariants.push_back(currentCoord.x + 1);
		}
		if (currentCoord.y > 0) {
			yVariants.push_back(currentCoord.y - 1);
		}
		yVariants.push_back(currentCoord.y);
		if (currentCoord.y < width - 1) {
			yVariants.push_back(currentCoord.y + 1);
		}

		for (auto x = xVariants.begin(); x != xVariants.end(); x++) {
			for (auto y = yVariants.begin(); y != yVariants.end(); y++) {
				if (cellsArray[*x][*y].getObject() == nullptr) {
					moves.push_back(&cellsArray[*x][*y]);
				}
			}
		}
	}
	return moves;
}

unsigned Prey::live(std::vector<Cell*> possibleMoves, std::list<LivingObject*>& listForNewObj) {
	if (health <= 0) {
		return 0;
	}
	health--;
	if (possibleMoves.empty()) {
		return 0;
	}
	size_t randomPick = rand() % possibleMoves.size();

	if (health == 6 || health == 3) {
		if (rand() % 100 < 55) {
			Prey* newObj = new Prey(possibleMoves[randomPick]);
			possibleMoves[randomPick]->setObject(newObj);
			listForNewObj.push_back(newObj);
			return 1;
		}
	}
	moveToCell(possibleMoves[randomPick]);
	return 0;
}

char Prey::getSymbol() const {
	return 'f';
}
