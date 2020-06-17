#pragma once
#include "LivingObject.h"

class Predator : public LivingObject {
public:
	Predator(Cell* cell);
	~Predator() override = default;
	std::vector<Cell*> possibleMoves(Cell** cellsArray, int height, int width) const override;
	unsigned live(std::vector<Cell*> possibleMoves, std::list<LivingObject*>& listForNewObj) override;
	virtual char getSymbol() const override;
};
