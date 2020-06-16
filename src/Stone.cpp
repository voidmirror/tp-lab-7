#include "Stone.h" //fix

Stone::Stone(Cell* cell) :Object(cell) {
	this->lifetime = StoneLifeTime;
	this->type = ObjectType::STONE;
};

void Stone::Live() {
	lifetime--;
};

char Stone::GetSymbol() {
	return STONE_S;
};