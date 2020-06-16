#pragma once
#include"Cell.h"
#include"Inanimate.h"

class Stone : public Inanimate {
public:
	Stone(Cell *cell = nullptr) : Inanimate::Inanimate(cell) { type = ObjType::STONE; }
	void live() {}
private:
};