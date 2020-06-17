#include "Predator.h"
#include "Prey.h"
#include <typeinfo>

class Prey;

Predator::Predator(Cell* cell) :
	LivingObject(cell) {
	health = 8;
}

std::vector<Cell*> Predator::possibleMoves(Cell** cellsArray, int height, int width) const {
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

			if (cellsArray[*x][currentCoord.y].getObject() == nullptr || typeid(*cellsArray[*x][currentCoord.y].getObject()) == typeid(Prey)) {
				moves.push_back(&cellsArray[*x][currentCoord.y]);
			}
		}

		for (auto y = yVariants.begin(); y != yVariants.end(); y++) {
			if (cellsArray[currentCoord.x][*y].getObject() == nullptr || typeid(*cellsArray[currentCoord.x][*y].getObject()) == typeid(Prey)) {
				moves.push_back(&cellsArray[currentCoord.x][*y]);
			}
		}
	}
	return moves;
}

unsigned Predator::live(std::vector<Cell*> possibleMoves, std::list<LivingObject*>& listForNewObj) {
	if (health <= 0) {
		return 0;
	}
	health--;
	if (possibleMoves.empty()) {
		return 0;
	}
	size_t randomPick = rand() % possibleMoves.size();

	if (health == 3 || health == 8) {
		if (rand() % 100 < 65) {
			Predator* newObj = new Predator(possibleMoves[randomPick]);
			possibleMoves[randomPick]->setObject(newObj);
			listForNewObj.push_back(newObj);
			return 1;
		}
	}

	if (possibleMoves[randomPick]->getObject() != nullptr && typeid(*possibleMoves[randomPick]->getObject()) == typeid(Prey)) {
		static_cast<Prey*>(possibleMoves[randomPick]->getObject())->setHealth(0);
		health += 5;
	}

	moveToCell(possibleMoves[randomPick]);
	return 0;
}

char Predator::getSymbol() const {
	return 's';
}
