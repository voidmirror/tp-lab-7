#include "Objects.h"

//
bool Empty(Cell* cell)
{
	if (cell->isEmpty()) return true;
	return false;
}
//
//
bool WherePrey(Cell* cell)
{
	if ((!cell->isEmpty()) && cell->object->getIcon() == 'f') return true;
	return false;
}
//
bool NotPredator(Cell* cell)
{
	if ((cell->isEmpty())|| (cell->object->getIcon() != 'S')) return true;
	return false;
}

//______________________________________


Object::Object(Cell* cell)
{
	this->cell = cell;
	liveTime = 0;
	DeathFlag = false;
}

Object::~Object()
{
}

int Object::getLiveTime()
{
	return liveTime;
}

bool Object::amIDead()
{
	return DeathFlag;
}

void Object::becomeDead()
{
	DeathFlag = true;
}

void Object::live()
{
	liveTime++;
}

char Object::getIcon()
{
	return '~';
}


//____________________________________________________




Stone::~Stone()
{
}

char Stone::getIcon()
{
	return icon;
}

//____________________________________________________


void Prey::movement()
{
	Cell* cellToMove = cell->findNear(Empty);
	if (cellToMove != nullptr) {
		cellToMove->addObject(this);
		cell->fishSwimAway();
		cell = cellToMove;
	}
}

int Prey::getTimeToLive()
{
	return timeToLive;
}

int Prey::getTimeToBorn()
{
	return timeToBorn;
}

Prey::~Prey()
{
}

void Prey::live()
{
	Object::live();
	if(!amIDying())
	{ 
		movement();
		if(amIGetChild()) newPrey();
	}
	else
	{
		cell->killObject();
	}
	
}

char Prey::getIcon()
{
	return icon;
}

bool Prey::amIDying()
{
	if (this->getLiveTime() == timeToLive)
	{
		return true;
	}
	return false;
}

bool Prey::amIGetChild()
{
	if (this->getLiveTime() % timeToBorn == 0)
	{
		return true;
	}
	return false;
}

void Prey::newPrey()
{
	Cell* cellForChild = cell->findNear(Empty);
	if (cellForChild != nullptr) {
		cellForChild->addObject(new Prey(cellForChild, timeToLive, timeToBorn));
	}
}

//____________________________________________________


Predator::~Predator()
{
}

void Predator::live()
{
	Object::live();
	if (!amIDying()) {
		if (amIGetChild())
		{
			newPredator();
		}
		if (hunger < 3) eating();
		movement();
	}
	else
	{
		cell->killObject();
	}
}

char Predator::getIcon()
{
	return icon;
}

bool Predator::amIDying()
{
	if (this->getLiveTime() > this->getTimeToLive() || hunger <= 0)
	{
		return true;
	}
		return false;
}

bool Predator::amIGetChild()
{
	if ((this->getLiveTime() % this->getTimeToBorn() == 0) && (hunger > 3)) {
		return true;
	}
	return false;
}

void Predator::eating()
{
	Cell* cellFish = cell->findNear(WherePrey);
	if (cellFish != nullptr)
	{
		cellFish->killObject();
		hunger++;
	}
}

void Predator::newPredator()
{
	Cell* cellToChild = cell->findNear(Empty);
	if (cellToChild != nullptr) {
		cellToChild->addObject(new Predator(cellToChild, this->getTimeToLive(), this->getTimeToBorn(), 3));
	}
}

void Predator::movement()
{
	Cell* cellToMove = cell->findNear(NotPredator);
	if (cellToMove != nullptr) {
		if (!cellToMove->isEmpty())
		{
			cellToMove->killObject();
			hunger++;
		}
		cellToMove->addObject(this);
		cell->fishSwimAway();
		cell = cellToMove;
	}
}


