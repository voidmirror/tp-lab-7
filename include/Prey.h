#pragma once
#include "LivingObject.h"

class Prey : public LivingObject {
public:
	Prey(Cell* cell);
	~Prey() override = default;
	std::vector<Cell*> possibleMoves(Cell** cellsArray, int height, int width) const override;
	unsigned live(std::vector<Cell*> possibleMoves, std::list<LivingObject*>& listForNewObj) override;
	virtual char getSymbol() const override;
};
