#include "Object.h"

//Object
Cell* Object::getCell() {
	return cell;
}

void Object::setCell(Cell* cl) {
	cell = cl;
}

ObjType Object::getObjectType() {
	return type;
}

int Object::getPower(){
	return power;
}

void Object::incDnum(int k) {
	etnum += k;
}

//Rock
Rock::Rock(int pwr) {
	type = ROCK;
	power = pwr;
}

ObjStat Rock::live(vector<Cell*> &ngbs) {
	return NoCHANGES;
}


//Prey
ObjStat Prey::live(vector<Cell*> &ngbs) {
	Cell* childcell = nullptr;
	Cell* mcell = nullptr;
	int a, size;

	livctr--;
	if (livctr == 0) {
		ngbs.clear();
		ngbs.push_back(cell);
		delete(this);
		return DIED;
	}

	repctr--;
	if (repctr == 0) {
		if (size = ngbs.size() != 0) {
			repctr = reptm;
			a = rand() % size;
			childcell = ngbs[a];
			ngbs.erase(ngbs.begin() + a);

			ngbs.push_back(cell);
			a = rand() % ngbs.size();
			mcell = ngbs[a];
			ngbs.clear();
			ngbs.push_back(cell);
			ngbs.push_back(mcell);
			ngbs.push_back(childcell);
			cell = mcell;
			return REPROD;
		}
		else {
			repctr++;
		}
	}
	if (ngbs.size() != 0) {
		ngbs.push_back(cell);
		a = rand() % ngbs.size();
		mcell = ngbs[a];
		ngbs.clear();
		ngbs.push_back(cell);
		ngbs.push_back(mcell);
		cell = mcell;
		return MOVED;
	}
	else {
		return NoCHANGES;
	}
}

Prey::Prey() {
	type = PREY;
	power = 100;
}

//Predator
Predator::Predator() {
	type = PREDATOR;
	power = 200;
	livctr = PredatorLife;
	etnum = PerdatorSatiety;
}

ObjStat Predator::live(vector<Cell*> &ngbs) {
	Cell* childcell = nullptr;
	Cell* mcell = nullptr;
	int a, size;

	livctr--;
	etnum--;
	if (livctr == 0 || etnum == 0) {
		ngbs.clear();
		ngbs.push_back(cell);
		delete(this);
		return DIED;
	}

	if (etnum >= repnum) {
		if (size = ngbs.size() != 0) {
			etnum -= 15;
			a = rand() % size;
			childcell = ngbs[a];
			ngbs.erase(ngbs.begin() + a);

			ngbs.push_back(cell);
			a = rand() % ngbs.size();
			mcell = ngbs[a];
			ngbs.clear();
			ngbs.push_back(cell);
			ngbs.push_back(mcell);
			ngbs.push_back(childcell);
			cell = mcell;
			return REPROD;
		}
	}
	if (ngbs.size() != 0) {
		ngbs.push_back(cell);
		a = rand() % ngbs.size();
		mcell = ngbs[a];
		ngbs.clear();
		ngbs.push_back(cell);
		ngbs.push_back(mcell);
		cell = mcell;
		return MOVED;
	}
	else {
		return NoCHANGES;
	}
}
