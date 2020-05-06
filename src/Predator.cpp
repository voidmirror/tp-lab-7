#include <time.h>
#include "Predator.h"
#include "Ocean.h"

Predator::Predator(){
	srand(time(NULL));
	type = ObjType::PREDATOR;
	lifetime = lifetime_predator_base + rand() % (lifetime_predator_base + 1);
	stomach = stomach_predator_cap + rand() % (int(stomach_predator_cap * 0.4) + 1);
	hunger = hunger_predator_cap + rand() % (int(hunger_predator_cap / 2) + 1);
}

void Predator::divide(){
	Ocean* oc = cell->getOcean();
	Cell* c = oc->checkAll(cell->getCoord());
	if (c != nullptr){
		Predator* child = new Predator();
		c->setObject(child);
		oc->addObject(child);
		stomach = stomach_predator_cap + rand() % (int(stomach_predator_cap * 0.4) + 1);
	}
}

void Predator::kill(){
	Ocean* oc = cell->getOcean();
	Cell* c = oc->checkAllForFood(cell->getCoord());
	if (c != nullptr){
		hunger = hunger_predator_cap + rand() % (int(hunger_predator_cap / 2) + 1);
		stomach--;
		oc->removeObject(c->getObject());
		oc->moveObject(this, c->getCoord());
		c->setObject(this);
	}
	else
		hunger--;
}

void Predator::live(){
	kill();
	move();
	lifetime--;
	if (stomach == 0)
		divide();
	if (hunger == 0){
		cell->killMe();
		return;
	}
	if (lifetime == 0){
		cell->killMe();
		return;
	}

}