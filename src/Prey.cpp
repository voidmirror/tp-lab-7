#include <iostream>
#include <time.h>
#include "Prey.h"
#include "Ocean.h"

Prey::Prey(){
	srand(time(NULL));
	type = ObjType::PREY;
	lifetime = lifetime_prey_base + rand() % (lifetime_prey_base + 1);
	dividefreq = dividetime_prey_base + rand() % (int(dividetime_prey_base / 2) + 1);
}

bool Prey::step(Dir dir, Object* obj){
	Pair axis = obj->getCell()->getCoord();
	Ocean* oc = obj->getCell()->getOcean();
	switch (dir){
	case LEFT:
		if (axis.x - 1 >= 0 && oc->checkEmptyness({ axis.x - 1, axis.y })){
			oc->moveObject(this, { axis.x - 1, axis.y });
			return 1;
		}
	case RIGHT:
		if (axis.x + 1 < N && oc->checkEmptyness({ axis.x + 1, axis.y })){
			oc->moveObject(this, { axis.x + 1, axis.y });
			return 1;
		}
	case UP:
		if (axis.y - 1 < M && oc->checkEmptyness({ axis.x, axis.y - 1})){
			oc->moveObject(this, { axis.x, axis.y - 1});
			return 1;
		}
	case DOWN:
		if (axis.y + 1 >= 0 && oc->checkEmptyness({ axis.x, axis.y + 1 })){
			oc->moveObject(this, { axis.x, axis.y + 1 });
			return 1;
		}
		
	}
	return 0;
}

void Prey::divide(){
	Ocean* oc = cell->getOcean();
	Cell* c = oc->checkAll(cell->getCoord());
	if (c != nullptr){
		Prey* child = new Prey();
		c->setObject(child);
		oc->addObject(child);
	}
}

void Prey::move(){
	switch (rand() % 4){
	case LEFT:
		if (step(LEFT, this)) break;
		break;
	case RIGHT:
		if (step(RIGHT, this)) break;
		break;
	case UP:
		if (step(UP, this)) break;
		break;
	case DOWN:
		if (step(DOWN, this)) break;
		break;
	}
}

void Prey::live(){
	move();
	lifetime--;
	dividefreq--;
	if (dividefreq == 0){
		divide();
		dividefreq = dividetime_prey_base + rand() % (int(dividetime_prey_base / 2) + 1);
	}
	if (lifetime == 0)
		cell->killMe();
}
