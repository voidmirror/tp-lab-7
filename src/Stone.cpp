#include "Cell.h"
#include "Ocean.h"
#include "Object.h"
#include "Stone.h"
#include "Prey.h"
#include "Predator.h"

#include "Additional.h"

Stone::Stone(Cell* cell) {
	this->cell = cell;
	alive = true;
	type = ObjectType::STONE;
}
void Stone::live() {}