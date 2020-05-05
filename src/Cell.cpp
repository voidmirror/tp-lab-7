#include "Cell.h"
#include "Ocean.h"
#include <vector>

using std::vector;

extern int di[], dj[];

Cell::Cell(Pair p, Ocean* oc) :coord(p), object(nullptr), ocean(oc) {

}


void Cell::init(Pair coord, Ocean* ocean) {
	this->coord = coord;
	this->ocean = ocean;
	this->object = nullptr;
}

Object* Cell::getObject() const {
	return object;
}

void Cell::setObject(Object* object) {
	this->object = object;
}

Cell* Cell::getNeighbour(bool isPredator) {
	vector<Cell*>neighbours;
	for (int k = 0; k < 4; k++) {
		if ((int)coord.x + di[k] >= 0 && (int)coord.x + di[k] < N && (int)coord.y + dj[k] >= 0 && (int)coord.y + dj[k] < M) {
			Pair newcoord = { (int)coord.x + di[k], (int)coord.y + dj[k] };
			Cell* newcell = ocean->getCell(newcoord.x, newcoord.y);
			if (!newcell->object) {
				neighbours.push_back(newcell);
			}
			else if (isPredator && newcell->object->getObjectType() == PREY_N) {
				neighbours.push_back(newcell);
				neighbours.push_back(newcell);
				neighbours.push_back(newcell);
			}
		}
	}
	if (neighbours.size() == 0) {
		return nullptr;
	}
	int index = rand() % neighbours.size();
	return neighbours[index];
}

Ocean* Cell::getOcean() {
	return ocean;
}

Cell::~Cell() {
	if (object)delete object;
}